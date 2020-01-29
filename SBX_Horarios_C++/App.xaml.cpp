#pragma once

#include "pch.h"
#include "App.xaml.h"
#include "MainPage.xaml.h"

using namespace PaatyDSM;

using namespace concurrency;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Interop;

/// <summary>
/// Initializes the singleton application object.
/// Esta es la primer línea de codigo ejecutado,
/// y como tal es el equivalente lógico de main() o WinMain().
/// </summary>
App::App()
{
	InitializeComponent();
	Application::Current->Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Función que se utiliza cuando la aplicación es lanzada normalmente por el usuario.
/// </summary>
void App::OnLaunched(LaunchActivatedEventArgs^ e)
{
	// El siguiente comando admite la navegación a páginas nuevas y mantiene un historial de navegación para navegar hacia adelante y hacia atrás.
	auto rootFrame = dynamic_cast<Frame^> (Window::Current->Content);

	// No repetir la inicialización cuando la ventana ya tiene contenido, solo asegurar que la ventana está activa.
	if (rootFrame == nullptr)
	{
		// Crear un Frame que actua como contexto de navegación.
		rootFrame = ref new Frame();

		rootFrame->NavigationFailed += ref new Windows::UI::Xaml::Navigation::NavigationFailedEventHandler(this, &App::OnNavigationFailed);

		///Specific Fix (bug#6161022)
		// Caché de navegación.
		rootFrame->CacheSize = 0;

		auto prerequisite = task<void>([]() {});

		if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
		{
			// Restore the saved session state only when appropriate, scheduling the
			// final launch steps after the restore is complete
			prerequisite = SuspensionManager::RestoreAsync();
		}

		if (e->PrelaunchActivated == false)
		{
			if (rootFrame->Content == nullptr)
			{
				// Cuando no se restaura la pila de navegación, navegar a la primera página,
				// configurando la nueva página pasándole la información requerida como
				// parámetro de navegación
				rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
			}
			// Poner el marco en la ventana actual
			Window::Current->Content = rootFrame;
			// Asegurarse de que la ventana actual está activa.
			Window::Current->Activate();
		}
	}
	else
	{
		if (e->PrelaunchActivated == false)
		{
			if (rootFrame->Content == nullptr)
			{
				// Cuando no se restaura la pila de navegación, navegar a la primera página,
				// configurando la nueva página pasándole la información requerida como
				// parámetro de navegación
				rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
			}
			// Asegurarse de que la ventana actual está activa.
			Window::Current->Activate();
		}
	}
}

/// <summary>
/// Se invoca al suspender la ejecución de la aplicación. El estado de la aplicación se guarda
/// sin saber si la aplicación finalizará o se reanudará con el contenido
/// de la memoria aún intacto.
/// </summary>
/// <param name="sender">Origen de la solicitud de suspensión.</param>
/// <param name="e">Detalles de la solicitud de suspensión.</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	// This is the time to save app data in case the process is terminated
	(void)sender;	// Unused parameter
	(void)e;		// Unused parameter

	auto deferral = e->SuspendingOperation->GetDeferral();
	SuspensionManager::SaveAsync().then([=]()
	{
		deferral->Complete();
	});
}

/// <summary>
/// Se invoca cuando la aplicación la inicia normalmente el usuario final. Se usarán otros puntos
/// </summary>
/// <param name="sender">Marco que produjo el error de navegación</param>
/// <param name="e">Detalles sobre el error de navegación</param>
void App::OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e)
{
	throw ref new FailureException("Problema al cargar la página " + e->SourcePageType.Name);
}

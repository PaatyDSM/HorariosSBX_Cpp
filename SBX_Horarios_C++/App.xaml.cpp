#pragma once

#include "pch.h"
#include "App.xaml.h"
#include "MainPage.xaml.h"

using namespace PaatyDSM;

using namespace concurrency;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml;

/// <summary>
/// Initializes the singleton application object.
/// Esta es la primer línea de codigo ejecutado,
/// y como tal es el equivalente lógico de main() o WinMain().
/// </summary>
App::App()
{
	InitializeComponent();
	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
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

		// Caché de navegación.
		rootFrame->CacheSize = 1;

		auto prerequisite = task<void> ( [] () {} );

		if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
		{
			// Restore the saved session state only when appropriate, scheduling the
			// final launch steps after the restore is complete
			prerequisite = SuspensionManager::RestoreAsync();
		}

		prerequisite.then
		( [=] (task<void> prerequisite)
		{
			try
			{
				prerequisite.get();
			}
			catch (Platform::Exception^)
			{
				throw ref new FailureException("Algo salió mal resumiendo la aplicación.");
				//Assume there is no state and continue
			}

			if (rootFrame->Content == nullptr)
			{
				// When the navigation stack isn't restored navigate to the first page,
				// configuring the new page by passing required information as a navigation
				// parameter
				rootFrame->Navigate(MainPage::typeid, e->Arguments);
			}

			// Place the frame in the current Window
			Window::Current->Content = rootFrame;

			// Ensure the current window is active
			Window::Current->Activate();

		},
			task_continuation_context::use_current()
		);
	}
	else
	{
		if (rootFrame->Content == nullptr)
		{
			// When the navigation stack isn't restored navigate to the first page,
			// configuring the new page by passing required information as a navigation
			// parameter
			if (!rootFrame->Navigate(MainPage::typeid, e->Arguments))
			{
				throw ref new FailureException("Algo salió mal.\nError desconocido :(");
			}
		}

		// Ensure the current window is active
		Window::Current->Activate();
	}
}

/// <summary>
/// Función que se utiliza cuando la ejecución de la aplicación  es suspendida.
/// El estado de la aplicación es guardado con el contenido en memoria intacto.
/// </summary>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	(void)sender;	// Unused parameter
	(void)e;		// Unused parameter

	auto deferral = e->SuspendingOperation->GetDeferral();
	SuspensionManager::SaveAsync().then([=]()
	{
		deferral->Complete();
	});
}
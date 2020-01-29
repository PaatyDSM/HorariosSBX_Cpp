#pragma once

#include "App.g.h"

using namespace Platform;
using namespace Windows::UI::Xaml::Navigation;

namespace SBX_HORARIOS
{
	/// <summary>
	/// Proporciona un comportamiento específico de la aplicación para complementar la clase Application predeterminada.
	/// </summary>
	ref class App sealed
	{
	public:
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;
		App();

	private:
		void OnSuspending(Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
		void OnNavigationFailed(Object ^sender, NavigationFailedEventArgs ^e);
	};
}



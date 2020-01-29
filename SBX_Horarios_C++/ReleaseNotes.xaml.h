#pragma once

#include "ReleaseNotes.g.h"
#include "SBX_HORARIOS_MAINAPP.xaml.h"

namespace PaatyDSM
{
	/// <summary>
	/// Una página vacía que se puede usar de forma independiente o a la que se puede navegar dentro de un objeto Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ReleaseNotes sealed
	{
	public:
		ReleaseNotes();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		MainPage^ rootPage;
		void Footer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Backbutton1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}

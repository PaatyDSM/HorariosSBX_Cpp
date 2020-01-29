#pragma once

#include "SBX_HORARIOS_MAINAPP.g.h"
#include "MainPage.xaml.h"

namespace PaatyDSM
{
	/// <summary>
	/// Page that displays available sample scenarios in a ListBox
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]

	public ref class SBX_HORARIOS_MAINAPP sealed
	{
	public:
		SBX_HORARIOS_MAINAPP();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		MainPage^ rootPage;
		void Footer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void send_legajo_button(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void NavigateToHorariosPage(void);
	};
}

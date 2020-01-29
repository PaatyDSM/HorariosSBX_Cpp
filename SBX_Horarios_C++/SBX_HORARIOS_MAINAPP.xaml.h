#pragma once

#include "SBX_HORARIOS_MAINAPP.g.h"
#include "MainPage.xaml.h"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;

namespace PaatyDSM
{
	/// <summary>
	/// Page that displays horarios in a table.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]

	public ref class SBX_HORARIOS_MAINAPP sealed
	{
	public:
		SBX_HORARIOS_MAINAPP();

	protected:
		virtual void OnNavigatedTo(NavigationEventArgs^ e) override;

	private:
		MainPage^ rootPage;

		void Footer_Click(Platform::Object^ sender, RoutedEventArgs^ e);
		void send_legajo_button(Platform::Object^ sender, RoutedEventArgs^ e);
		void release_notes_button(Platform::Object^ sender, RoutedEventArgs^ e);
		void NavigateToHorariosPage(void);
		void read_legajo(void);
	};
}

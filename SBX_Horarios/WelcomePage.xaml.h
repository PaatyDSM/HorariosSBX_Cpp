#pragma once

#include "WelcomePage.g.h"
#include "MainPage.xaml.h"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;

namespace SBX_HORARIOS
{
	/// <summary>
	/// Página que muestra los horarios en formato de lista.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]

	public ref class WelcomePage sealed
	{
	public:
		WelcomePage();

	protected:
		virtual void OnNavigatedTo(NavigationEventArgs^ e) override;

	private:
		MainPage^ rootPage;

		void start_FadeInAnimation(void);
		void start_FadeOutAnimation(void);
		void start_FadeOutAnimation2(void);
		void Footer_Click(Platform::Object^ sender, RoutedEventArgs^ e);
		void send_legajo_button(Platform::Object^ sender, RoutedEventArgs^ e);
		void Release_Notes_Click(Platform::Object^ sender, RoutedEventArgs^ e);
		void NavigateToHorariosPage(void);
		void read_legajo(void);
	};
}



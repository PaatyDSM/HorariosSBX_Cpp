#pragma once

#include "HorariosPage.g.h"
#include "WelcomePage.xaml.h"

namespace SBX_HORARIOS
{
	/// <summary>
	/// Una página vacía que se puede usar de forma independiente o a la que se puede navegar dentro de un objeto Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]

	public ref class HorariosPage sealed
	{
	public:
		HorariosPage();

	protected:
		virtual void OnNavigatedTo(NavigationEventArgs^ e) override;

	private:
		MainPage^ rootPage;

		Windows::Web::Http::Filters::HttpBaseProtocolFilter^ filter;
		Windows::Web::Http::HttpClient^ httpClient;

		void start_FadeInAnimation(void);
		void start_FadeOutAnimation(void);
		void start_FadeOutAnimation2(void);
		void send_pagewithlegajo(int);
		void BackgroundTask(String^ e, int);
		void Backbutton1(Object^ sender, RoutedEventArgs^ e);
		void GoPageBack(void);
		void Footer_Click(Object^ sender, RoutedEventArgs^ e);
		void save_legajo(int);
		void save_cache(String^ e);
		void read_cache(int);
	};
}

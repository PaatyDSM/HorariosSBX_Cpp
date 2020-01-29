#pragma once

#include "pch.h"
#include "HorariosPage.g.h"
#include "MainPage.xaml.h"
#include "SBX_HORARIOS_MAINAPP.xaml.h"

namespace PaatyDSM
{
	namespace HttpClientSample
	{
		/// <summary>
		/// An empty page that can be used on its own or navigated to within a Frame.
		/// </summary>
		[Windows::Foundation::Metadata::WebHostHidden]
		public ref class Horarios sealed
		{
		public:
			Horarios();
		protected:
			virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		private:
			MainPage^ rootPage;
			Windows::Web::Http::Filters::HttpBaseProtocolFilter^ filter;
			Windows::Web::Http::HttpClient^ httpClient;
			void send_pagewithlegajo(int);
			void Backbutton1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
			void GoBack(void);
			void Footer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		};
		
	}
}

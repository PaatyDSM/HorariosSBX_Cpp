#pragma once

#include "MainPage.g.h"
#include "MainPage.xaml.h"

using namespace Platform;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Phone::UI::Input;

namespace PaatyDSM
{
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};

	/// <summary>
	/// MainPage holds the Status Block and the Frame in which all the pages are loaded.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo(NavigationEventArgs^ e) override;

	private:
		//On press Hardware Back Button
		void MainPage::HardwareBackButtonPressed(Object^ sender, BackPressedEventArgs^ e)
		{
			// Clear the status block when navigating
			Current->NotifyUser("", NotifyType::StatusMessage);

			/// Specific Fix (bug#6161021)
			// If it's possible to Navigate back and if the event has not already been handled
			if (Page_Frame->CanGoBack && e->Handled == true)
			{
				Frame->Navigate(MainPage::typeid, safe_cast<Object^>(0));
			}
			else
			{
				if (Page_Frame->CanGoBack)
				{
					Frame->Navigate(MainPage::typeid, safe_cast<Object^>(0));
					e->Handled = true;
				}
				else
				{
					// Exit app.
					e->Handled = false;
				}
			}
		}

	internal:
		static MainPage^ Current;
		void NotifyUser(String^ strMessage, NotifyType type);
	};
}

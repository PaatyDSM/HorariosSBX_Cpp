#include "pch.h"
#include "MainPage.xaml.h"
#include "WelcomePage.xaml.h"

using namespace SBX_HORARIOS;
using namespace std;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Interop;
using namespace Platform;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::ViewManagement;
using namespace Windows::System::Profile;

// Referencia al Frame en el cual todas las páginas son cargadas.
MainPage^ MainPage::Current = nullptr;
//DispatcherTimer^ dispatcherTimer;

// Main
MainPage::MainPage()
{
	InitializeComponent();

	// This is a static public property that allows downstream pages to get a handle
	// to the MainPage instance in order to call methods that are in this class.
	MainPage::Current = this;
}

// OnNavigatedTo function
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	//Check trial
	/// DISABLED ///
#pragma region TRIAL
	/*
	{
		Windows::Globalization::Calendar^ c = ref new Windows::Globalization::Calendar;
		String^ trial = c->YearAsString();
		wstring w_trial(trial->Data());
		wstring wide_year(w_trial);
		string year(wide_year.begin(), wide_year.end());
		int year_number = stoi(year);
		if (year_number > 2017)
		{
			Page_Frame->Navigate(TypeName{ "SBX_HORARIOS.TrialPage", TypeKind::Custom });
		}
	}
	*/
#pragma endregion
	/// DISABLED ///

	// Launch UWP apps in full-screen mode on mobile devices or tablets.
	SetFullScreenModeON();

	// When the navigation stack isn't restored navigate to the WelcomePage
	if (Page_Frame->Content == nullptr)
	{
		if (!Page_Frame->Navigate(TypeName{"SBX_HORARIOS.WelcomePage", TypeKind::Custom}))
		{
			// Clear the status block
			NotifyUser("Hubo un problema al cargar la página principal.", NotifyType::ErrorMessage);
		}
	}

	// Initialize DispatcherTimer
	//dispatcherTimer = ref new DispatcherTimer;
}

// StatusBlock function
void MainPage::NotifyUser(String^ strMessage, NotifyType type)
{
	switch (type)
	{
	case NotifyType::StatusMessage:
		StatusBorder->Background = ref new SolidColorBrush(Windows::UI::Colors::Green);
		break;
	case NotifyType::ErrorMessage:
		StatusBorder->Background = ref new SolidColorBrush(Windows::UI::Colors::Red);
		break;
	case NotifyType::DebugMessage:
		StatusBorder->Background = ref new SolidColorBrush(Windows::UI::Colors::Yellow);
		break;
	default:
		break;
	}
	StatusBlock->Text = strMessage;

	// Collapsed the StatusBlock if it has no text to conserve real estate.
	if (StatusBlock->Text != "")
	{
		StatusBorder->Visibility = Windows::UI::Xaml::Visibility::Visible;
	}
	else
	{
		StatusBorder->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	}
}

// Set fullscreen
void MainPage::SetFullScreenModeON()
{
	// Launch UWP apps in full-screen mode on mobile devices or tablets.
	{
		String^ platformFamily = AnalyticsInfo::VersionInfo->DeviceFamily;

		if (platformFamily->Equals("Windows.Mobile"))
		{
			ApplicationView^ view = ApplicationView::GetForCurrentView();
			view->TryEnterFullScreenMode();
		}
	}
}

/// DISABLED ///
#pragma region AutoHide NotifyUser
// Await 'ms' amount of time
void MainPage::Await(int ms, bool stop)
{
	//if (!stop)
	//{
		// Set Tick duration
		//time_amount.Duration = ms;
		//dispatcherTimer->Interval = time_amount;
		// Register event handler for Tick event
		//auto registrationtoken = dispatcherTimer->Tick += ref new EventHandler<Object^>(this, &MainPage::HideMessage);
	//}
}

// Clear and hide Messages
void MainPage::HideMessage(Object^ sender, Object^ args)
{
	//auto dTIString = dispatcherTimer->Interval.ToString();
	//if (dTIString = "0")
	//{
	//	Await(0, true);
	//	return;
	//}
	//else 
	//{
	//	NotifyUser("", NotifyType::StatusMessage);
	//	// Stop the timer
	//	dispatcherTimer->Stop();
	//}
}
#pragma endregion


#include "pch.h"

#include "MainPage.xaml.h"
#include "WelcomePage.xaml.h"

using namespace SBX_HORARIOS;

using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Interop;

// Referencia al Frame en el cual todas las páginas son cargadas.
MainPage^ MainPage::Current = nullptr;

MainPage::MainPage()
{
	InitializeComponent();

	// This is a static public property that allows downstream pages to get a handle
	// to the MainPage instance in order to call methods that are in this class.
	MainPage::Current = this;

	// Launch UWP apps in full-screen mode on mobile devices or tablets.
	{
		String^ platformFamily = Windows::System::Profile::AnalyticsInfo::VersionInfo->DeviceFamily;

		if (platformFamily->Equals("Windows.Mobile"))
		{
			/// SpecificFix Crash on Desktop
			// Called when Hardware Back Button is pressed
			HardwareButtons::BackPressed += ref new EventHandler<BackPressedEventArgs ^>(this, &MainPage::HardwareButtons_BackPressed);

			Windows::UI::ViewManagement::ApplicationView^ view = Windows::UI::ViewManagement::ApplicationView::GetForCurrentView();

			view->TryEnterFullScreenMode();
		}
	}

}

// OnNavigatedTo function
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	/// Specific Fix (bug#6161012), (bug#6161013) & AfterSuspensionRandomCrash.
	if (Page_Frame->Content == nullptr)
	{
		// When the navigation stack isn't restored navigate to the WelcomePage
		if (!Page_Frame->Navigate(TypeName{ "SBX_HORARIOS.WelcomePage", TypeKind::Custom }))
		{
			throw ref new FailureException("Error al cargar la página principal.\nDetalles del error: " + e);
		}
	}
	else
	{
		// null
	}
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

// On Hardware Back Button press
void MainPage::HardwareButtons_BackPressed(Object^ sender, Windows::Phone::UI::Input::BackPressedEventArgs^ e)
{
	if (this->Page_Frame->CanGoBack)
	{
		e->Handled = true;

		// Clear the status block when navigating
		NotifyUser("", NotifyType::StatusMessage);

		///Specific Fix (bug#6161022)
		// Clear the navigation stacks using the Clear method of each stack.
		Page_Frame->BackStack->Clear();
	}
	else
	{
		e->Handled = false;
	}

	///Specific Fix (bug#6161022)
	// Clear the navigation stacks using the Clear method of each stack.
	Page_Frame->BackStack->Clear();

	// Back to WelcomePage
	Page_Frame->Navigate(TypeName{ "SBX_HORARIOS.WelcomePage", TypeKind::Custom });

}


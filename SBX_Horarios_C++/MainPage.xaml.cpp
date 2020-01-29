#include "pch.h"
#include "MainPage.xaml.h"
#include "SBX_HORARIOS_MAINAPP.xaml.h"

using namespace PaatyDSM;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Phone::UI::Input;

using namespace std;

MainPage^ MainPage::Current = nullptr;

MainPage::MainPage()
{
	InitializeComponent();

	// This is a static public property that allows downstream pages to get a handle to the MainPage instance
	// in order to call methods that are in this class.
	MainPage::Current = this;

	HardwareButtons::BackPressed += ref new EventHandler<BackPressedEventArgs ^>(this, &MainPage::HardwareButtons_BackPressed);
}

void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	SuspensionManager::RegisterFrame(Page_Frame, "PaatyDSM.SBX_HORARIOS_MAINAPP");
	if (Page_Frame->Content == nullptr)
	{
		// When the navigation stack isn't restored navigate to the SBX_HORARIOS_MAINAPP
		if (!Page_Frame->Navigate(TypeName{ "PaatyDSM.SBX_HORARIOS_MAINAPP", TypeKind::Custom }))
		{
			throw ref new FailureException("Fallo al iniciar la App :(\n.\nCodigo de error: \n#31326497.\nContacte al editor de la aplicación\ne incluya el #codigo de error.");
		}
	}
}

void MainPage::HardwareButtons_BackPressed(Object^ sender, Windows::Phone::UI::Input::BackPressedEventArgs^ e)
{
	// Clear the status block when navigating
	NotifyUser("", NotifyType::StatusMessage);

	if (Page_Frame->CanGoBack)
	{
		///Specific fix. bug#6161001
		//Indicate the back button press is handled so the app does not exit
		e->Handled = true;
		///Specific Fix: (bug#6161009)
		Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(PaatyDSM::MainPage::typeid));
	}
	else
	{
		e->Handled = false;
	}

}
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
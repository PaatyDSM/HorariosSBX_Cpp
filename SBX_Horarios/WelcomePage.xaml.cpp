#include "pch.h"

#include "WelcomePage.xaml.h"
#include "HorariosPage.xaml.h"
#include "ReleaseNotesPage.xaml.h"

#include "fstream"

using namespace SBX_HORARIOS;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::Phone::UI::Input;

using namespace std;

WelcomePage::WelcomePage()
{
	InitializeComponent();
}

// Function start_fadein_animation
void WelcomePage::WelcomePage::start_FadeInAnimation(void)
{
	WelcomepPage_Storyboard->Begin();
}

// Function start_fadeout_animation
void WelcomePage::WelcomePage::start_FadeOutAnimation(void)
{
	WelcomepPage_Storyboard2->Begin();
}

// Function start_fadeout_animation
void WelcomePage::WelcomePage::start_FadeOutAnimation2(void)
{
	TransitionColorFix1->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
	WelcomepPage_Storyboard3->Begin();
}

// OnNavigatedTo function
void WelcomePage::OnNavigatedTo(NavigationEventArgs^ e)
{
	// A pointer back to the main page.  This is needed if you want to call methods in MainPage such as NotifyUser()
	rootPage = MainPage::Current;

	// Read last used legajo
	read_legajo();
}

// On click 'Consultar Horarios' validate Legajo and send it to the next page 'HorariosPage'
void WelcomePage::send_legajo_button(Object^ sender, RoutedEventArgs^ e)
{
	// Clear errors
		rootPage->NotifyUser("", NotifyType::StatusMessage);

	///MyFunction
	// Convert String^ to string
		String^ str = main_legajo_input->Text;
		wstring w_str(str->Data());
		wstring wide(w_str);
		string str2(wide.begin(), wide.end());

	// Check if 'legajo' is valid
		size_t check = str2.find_first_not_of("0123456789");

	// Error handler and error messages
		// If no input
		if (str2.length() == 0)
		{
			rootPage->NotifyUser("Primero debe ingresar un legajo.", NotifyType::ErrorMessage);
		}
		// If illegal character
		else if (check != string::npos)
		{
			rootPage->NotifyUser("El legajo ingresado no es válido", NotifyType::ErrorMessage);
		}
		// If valid
		else
		{
			// Goto NEXT FUNCTION
			start_FadeOutAnimation();
		}

}

// On click 'Hyperlinks'
void WelcomePage::Footer_Click(Object^ sender, RoutedEventArgs^ e)
{
	auto uri = ref new Uri((String^)((HyperlinkButton^)sender)->Tag);
	Windows::System::Launcher::LaunchUriAsync(uri);
}

// Go to HorariosPage and send it legajo
void SBX_HORARIOS::WelcomePage::NavigateToHorariosPage()
{
	this->Frame->Navigate(TypeName(HorariosPage::typeid), main_legajo_input->Text);
}

// On click 'Version number' navigate to 'Release Notes Page'
void WelcomePage::Release_Notes_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(ReleaseNotesPage::typeid));
}

// Read last used legajo
void WelcomePage::read_legajo(void)
{
	// Path for local saving
		String^ localfolder = ApplicationData::Current->LocalFolder->Path;

	// Convert String^ to string
		wstring folderNameW(localfolder->Begin());
		string folderName(folderNameW.begin(), folderNameW.end());

	// Filename
		string filename = folderName + "\\lastlegajo.tmp";

	// Read file
		char fileData[256]="";
		ifstream in(filename);
		if (in)
		{
			in >> fileData;
			in.close();
		}

	// Convert char to String^
		string s_filedata = string(fileData);
		wstring w_filedata = wstring(s_filedata.begin(), s_filedata.end());
		String^ str_fileData = ref new String(w_filedata.c_str());

	// Put legajo into TextBox
		main_legajo_input->Text = str_fileData;
}

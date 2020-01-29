#include "pch.h"
#include "SBX_HORARIOS_MAINAPP.xaml.h"
#include "HorariosPage.xaml.h"
#include "MainPage.xaml.h"

#include <stdlib.h>
#include <string.h>

using namespace PaatyDSM;
using namespace PaatyDSM::HttpClientSample;
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

SBX_HORARIOS_MAINAPP::SBX_HORARIOS_MAINAPP()
{
	InitializeComponent();
}

/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void SBX_HORARIOS_MAINAPP::OnNavigatedTo(NavigationEventArgs^ e)
{
	rootPage = MainPage::Current;
}

//On Click 'Hyperlinks'
void SBX_HORARIOS_MAINAPP::Footer_Click(Object^ sender, RoutedEventArgs^ e)
{
	auto uri = ref new Uri((String^)((HyperlinkButton^)sender)->Tag);
	Windows::System::Launcher::LaunchUriAsync(uri);
}

//On click 'Consultar Horarios' validate Legajo and send it to the next page 'HorariosPage'
void SBX_HORARIOS_MAINAPP::send_legajo_button(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	///MyFunction
	//Make reference for Text in the Textboxs
	String^ str = main_legajo_input->Text;

	//Convert String^ to wstring
	wstring w_str(str->Data());

	//Convert wstring to string
	wstring wide(w_str);
	string str2(wide.begin(), wide.end());

	//Check if 'legajo' is valid
	size_t check = str2.find_first_not_of("0123456789");

	//Error handler and error messages
	if (str2.length() == 0)
	{
		rootPage->NotifyUser("Primero debe ingresar un legajo.", NotifyType::ErrorMessage);
	}
	else if (check != string::npos)
	{
		rootPage->NotifyUser("El legajo ingresado no es válido", NotifyType::ErrorMessage);
	}
	else
	{
		NavigateToHorariosPage();
	}

}

	//Go to HorariosPage and send it legajo
	void PaatyDSM::SBX_HORARIOS_MAINAPP::NavigateToHorariosPage()
	{
		this->Frame->Navigate(TypeName(Horarios::typeid), main_legajo_input->Text);
	}


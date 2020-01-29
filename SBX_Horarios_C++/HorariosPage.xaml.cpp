#include "pch.h"

#include "HorariosPage.xaml.h"
#include "MainPage.xaml.h"
#include "SBX_HORARIOS_MAINAPP.xaml.h"


#include "Sample-Utils\Helpers.h"

using namespace PaatyDSM;

using namespace Platform;
using namespace concurrency;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Web::Http;
using namespace Windows::Web::Http::Filters;

using namespace std;

PaatyDSM::Horarios::Horarios()
{
	InitializeComponent();
}

// OnNavigatedTo function
void Horarios::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void)e;   // Unused parameter

	// A pointer back to the main page.  This is needed if you want to call methods in MainPage such as NotifyUser()
	rootPage = MainPage::Current;

	///Specific fix
	// Clean error messages 
	rootPage->NotifyUser("", NotifyType::StatusMessage);

	//Save received parameter like a reference called str
	String^ str = (String^)e->Parameter;

	//Starting  filters and httpclient
	filter = ref new HttpBaseProtocolFilter();
	httpClient = ref new HttpClient(filter);
	
	//Convert String^ to wstring
	wstring w_str(str->Data());

	//Convert wstring to string
	wstring wide(w_str);
	string str3(wide.begin(), wide.end());

	//Convert string to int
	int legajo = stoi(str3);

	//error handler
	if (e != nullptr) // Safe to use str.
	{ 
		// Go to
		send_pagewithlegajo(legajo);
	}
	else // Do not use data.
	{ 
		// Show error.
		rootPage->NotifyUser("Error interno: #31326496.\nContacte al editor de la aplicación\ne incluya el #codigo de error.", NotifyType::ErrorMessage);
		GoPageBack();
	}
}

// Send Legajo function
void Horarios::send_pagewithlegajo(int legajo)
{
	///Specific Fix
	rootPage->NotifyUser("Obteniendo horarios...", NotifyType::StatusMessage);

	//Alsea Proveedores
	///http:://proveedores.alsea.com.ar:25080/asignaciones-server/mobile/main/asignaciones/legajos/35052 + legajo

	//Get input legajo and append it to the url
	string s_legajo = to_string(legajo);
	string var = "http://proveedores.alsea.com.ar:25080/asignaciones-server/mobile/main/asignaciones/legajos/" + s_legajo;

	//Converts string to wstring
	wstring url_ok(var.begin(), var.end());

	//URL DATA
	Uri^ uri;

	//Reference to the new url page connection with legajo included
	String^ uriString = ref new String(url_ok.c_str());

	//CacheControl
	filter->CacheControl->ReadBehavior = HttpCacheReadBehavior::MostRecent;
	filter->CacheControl->WriteBehavior = HttpCacheWriteBehavior::NoCache;

	// Do an asynchronous GET. We need to use use_current() with the continuations since the tasks are completed on
	// background threads and we need to run on the UI thread to update the UI.

	create_task(httpClient->GetAsync(ref new Uri(uriString))).then([=](HttpResponseMessage^ response)
	{
		return Helpers::DisplayTextResultAsync(response, OutputField);
	},
		task_continuation_context::use_current()).then
		(
			[=](task<HttpResponseMessage^> previousTask)
	{
		unsigned short int internet_conn_status = 0;
		try
		{
			// Check if any previous task threw an exception.
			HttpResponseMessage^ response = previousTask.get();
		}
		///Specific Fix: bug#6161008
		catch (Exception^ ex)
		{
			internet_conn_status = 1;

			rootPage->NotifyUser("Error. No hay conexión a internet.", NotifyType::ErrorMessage);
		}

		// If no error connection occurs then initialize parse_Json
		if (internet_conn_status == 0)
		{
			//parse_json
			MainPage::Current->DataContext = ref new User();

			// Error Handlers
			try
			{
				MainPage::Current->DataContext = ref new User(OutputField->Text);

				///MyFunction2
				//Make reference for Text in the Textboxs
				String^ str = OutputField->Text;

				//Convert String^ to wstring
				wstring w_str(str->Data());

				//Convert wstring to string
				wstring wide(w_str);
				string str3(wide.begin(), wide.end());

				//Find ':[{' string to check if the data contains a valid legajo info
				size_t found = str3.find(":[{");

				//If true
				if (found != std::string::npos)
				{
					// Show successfull!
					rootPage->NotifyUser("Horarios recibidos!", NotifyType::StatusMessage);
				}
				else
				{
					rootPage->NotifyUser("El legajo no existe!", NotifyType::ErrorMessage);
					GoPageBack();
				}
			}
			catch (Exception^ ex)
			{
				rootPage->NotifyUser("Error: La base de datos del servidor está dañada.\nPor favor contacte al proveedor", NotifyType::ErrorMessage);
			}
		}
		else
		{
			/// Specific Fix (bug#6161010)
			//INCOMPLETE
			//If no internet connection is available get check if the last legajo obtained is equal to the actual legajo and read it from the cache.
			//Show an error and adverts that the content is from cache.
			
			// Go Back
			GoPageBack();
		}

	}
	);

}

// Hyperlink buttons
void Horarios::Footer_Click(Object^ sender, RoutedEventArgs^ e)
{
	auto uri = ref new Uri((String^)((HyperlinkButton^)sender)->Tag);
	Windows::System::Launcher::LaunchUriAsync(uri);
}

//Go back to MainPage with uncleared errors
void Horarios::GoPageBack()
{
	///Specific Fix (#bug6161013)
	OutputField->Text = "{\"asignaciones\":[],\"fechaConsulta\":\"\",\"legajo\":\"\"}";
	MainPage::Current->DataContext = ref new User(OutputField->Text);

	// Go to page
	Frame->Navigate(TypeName(PaatyDSM::SBX_HORARIOS_MAINAPP::typeid));
}

//Navigation: Back Button
void Horarios::Backbutton1(Object^ sender, RoutedEventArgs^ e)
{
	///Specific Fix (#bug6161013)
	OutputField->Text = "{\"asignaciones\":[],\"fechaConsulta\":\"\",\"legajo\":\"\"}";
	MainPage::Current->DataContext = ref new User(OutputField->Text);

	//Clears StatusBlock
	rootPage->NotifyUser("", NotifyType::StatusMessage);

	// Go to page
	Frame->Navigate(TypeName(PaatyDSM::SBX_HORARIOS_MAINAPP::typeid));
}
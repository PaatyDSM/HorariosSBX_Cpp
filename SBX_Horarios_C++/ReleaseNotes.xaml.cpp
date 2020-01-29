#include "pch.h"
#include "ReleaseNotes.xaml.h"
#include "MainPage.xaml.h"

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

ReleaseNotes::ReleaseNotes()
{
	InitializeComponent();
}


	/// <param name="e">Event data that describes how this page was reached.  The Parameter
	/// property is typically used to configure the page.</param>
void ReleaseNotes::OnNavigatedTo(NavigationEventArgs^ e)
{
	// A pointer back to the main page.  This is needed if you want to call methods in MainPage such as NotifyUser()
	rootPage = MainPage::Current;

	// Clean error messages from previous page
	rootPage->NotifyUser("", NotifyType::StatusMessage);

	Notes->Text =

		"Release Notes:\n"
		"\n"
		"V0.87b\n"
		"*Added better handler for no internet connection.\n"
		"*Fixed when a legajo is not found in database it won't show an error.\n"
		"*A lot of changes in the source code.\n"
		"*Fixed no internet connection incorrect message.(bug#6161008).\n"
		"*Fixed Hardware Back Button bug.\n"
		"*Changes in the UI.\n"
		"\t- Fixed some misaligned objects in landscape mode.\n"
		"\t- Fixed some background colors.\n"
		"*Fixed Screen flickering when pressing Hardware Back button.\n"
		"Fixed release notes separator.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*When Hardware Back Button is pressed, the app stop working correclty.(bug#6161012)"
		"*Random crash occurs when restoring from suspension.\n"
		"*Horarios Page is not working after pressing Hardware Back button.\n"
		"*!Partialy fixed horarios don't clean up when navigate back.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.86b\n"
		"*Fixed Screen flickering in the Main Page.(bug#6161001).\n"
		"*Fixed can't exit from the app pressing Hardware Back button.\n"
		"*Changes in the UI.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Screen flickering when pressing Hardware Back button.(bug#6161009).\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"*After restoring app from suspension, Hardware Back Button is not working correctly in Horarios Page.\n"
		"*When no internet connection is available it shows incorrect message.(bug#6161008).\n"
		"*Random crash occurs when restoring from suspension.\n"
		"*Horarios don't clean up when navigate back.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.85b\n"
		"*Fixed release notes aren't being displayed.\n"
		"*Fixed minor bugs.\n"
		"*Redesigned Horarios Scroll List.\n"
		"*Removed unused code"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Screen flickering in the Main Page when pressing Hardware Back button.(bug#6161001).\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"*After suspension, Hardware Back Button is not working correctly.\n"
		"*Random crash occurs when restoring from suspension.\n"
		"*Can't exit from the app pressing Hardware Back button.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.84b\n"
		"*Centered some graphics in Horarios Page.\n"
		"*Fixed Hyperlinks in Release Notes Page aren't working.\n"
		"*Fixed when navigating to Release Notes Page with a previous error messages, the error messages still appears.\n"
		"*Fixed Release Notes button should not be active in the Release Notes page.\n"
		"*Fixed author hyperlink size in Release Notes page.\n"
		"*Fixed some texts.\n"
		"*Changes in the source code for easy identification.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Screen flickering in the Main Page when pressing Hardware Back button.(bug#6161001).\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"*After suspension, Hardware Back Button is not working correctly.\n"
		"*Random crash occurs when restoring from suspension.\n"
		"*The store column is not sized correctly.\n"
		"*Release notes aren't being displayed.\n"
		"*When navigating to Release Notes Page with a previous error messages, the error messages still appears.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.83b\n"
		"*Fixed some misaligned graphics.\n"
		"*Fixed some graphic corruptions.\n"
		"*Fixed some texts.\n"
		"*Fixed Release Notes button functionality.\n"
		"*Fixed hyperlinks functionality.\n"
		"*Fixed left side of the scroll list is out of screen in portrait mode.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Screen flickering in the Main Page when pressing Hardware Back button.(bug#6161001).\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"*After suspension, Hardware Back Button is not working correctly.\n"
		"*Random crash occurs when restoring from suspension.\n"
		"The store column is not sized correctly.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.82b\n"
		"*Redesigned Main Page.\n"
		"*Redesigned Horarios Page.\n"
		"*Fix autoadaptive content in all pages.\n"
		"*Fixed landscape and portrait mode.\n"
		"*Added Release Notes Page.\n"
		"*Fixed hyperlinks directions.\n"
		"*Changed some translations.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Screen flickering in the Main Page when pressing Hardware Back button.(bug#6161001).\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"*In portrait mode the left side of the scroll list is out of screen.\n"
		"*Rekease Notes button is not working.\n"
		"*After suspension, Hardware Back Button is not working correctly.\n"
		"*Random crash occurs when restoring from suspension.\n"
		"*Hyperlinks buttons doesn't work anymore.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.81b\n"
		"*Added most icons and splash screens.\n"
		"*Cleaning code.\n"
		"*Reduced sizes in images.\n"
		"*Changed some texts.\n"
		"*Changes in the UI.\n"
		"*Alignments in the UI.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Landscape mode is not being showed correctly.\n"
		"*Screen flickering in the Main Page when pressing Hardware Back button.(bug#6161001)\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.8a\n"
		"*Now app is fully working.\n"
		"*Fixed some translations.\n"
		"*Fixed Back Button.\n"
		"\t- Now pressing Hardware Back button should always go back to the Main Page.\n"
		"*Added app version in the Main Page.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Landscape mode is not being showed correctly.\n"
		"*Screen flickering in the Main Page when pressing Hardware Back button.(bug#6161001)\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.7a\n"
		"*Fixed some error messages.\n"
		"*Now, empty legajo is rejected.\n"
		"*Fixed all error handlers.\n"
		"\t- Green message status now close when navigate back.\n"
		"\t- Database errors are reported correctly now.\n"
		"*Improvements in the UI.\n"
		"*Minor changes in the UI.\n"
		"*Fixed minor bugs.\n"
		"*Changes in the Source Code and cleaning.\n"
		"*Removed more unused code.\n"
		"*Fixed User Agent(Mozilla / 5.0).\n"
		"*Now the database can be parsed if it's loaded from the internet.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*Landscape mode is not being showed correctly.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.6a\n"
		"*Changes in the UI.\n"
		"*Changes in the source code for easy identification.\n"
		"*Removed unused code.\n"
		"*Fix for small screens.\n"
		"*Fixed hyperlink buttons.\n"
		"*Fix for Autoadaptive Content in the Horarios Page.\n"
		"*Fixed spanish translations.\n"
		"*Fixed error messages in Main Page.\n"
		"*Optimized code.\n"
		"*Aligned some texts.\n"
		"*Fixed error handlers.\n"
		"\n"
		"Know Bugs :\n"
		"*Empty legajo is acepted.\n"
		"*Loading message is not being show.\n"
		"*Green message status doesn't close when going back to the Main Page.\n"
		"*Database errors are now reported.\n"
		"*The database can't be parsed if it readed from the internet\n"
		"*Landscape mode is not being showed correctly.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.1\n"
		"(Nov / 7 / 2016)\n"
		"*First Release.\n"
		"\n";

}

//On Click 'Hyperlinks'
void ReleaseNotes::Footer_Click(Object^ sender, RoutedEventArgs^ e)
{
	auto uri = ref new Uri((String^)((HyperlinkButton^)sender)->Tag);
	Windows::System::Launcher::LaunchUriAsync(uri);
}

//Navigation: Back Button
void ReleaseNotes::Backbutton1(Object^ sender, RoutedEventArgs^ e)
{
	rootPage->NotifyUser("", NotifyType::StatusMessage);
	Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(PaatyDSM::SBX_HORARIOS_MAINAPP::typeid));
}
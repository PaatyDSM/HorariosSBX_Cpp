﻿#include "pch.h"

#include "ReleaseNotesPage.xaml.h"
#include "MainPage.xaml.h"

using namespace SBX_HORARIOS;

using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Interop;

ReleaseNotesPage::ReleaseNotesPage()
{
	InitializeComponent();
}

// Function start_fadein_animation
void ReleaseNotesPage::ReleaseNotesPage::start_FadeInAnimation(void)
{
	ReleaseNotes_Storyboard->Begin();
}

// Function start_fadeout_animation
void ReleaseNotesPage::ReleaseNotesPage::start_FadeOutAnimation(void)
{
	ReleaseNotes_Storyboard2->Begin();
}

void ReleaseNotesPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	// A pointer back to the main page.  This is needed if you want to call methods in MainPage such as NotifyUser()
	rootPage = MainPage::Current;

	// Clean error messages from previous page
	rootPage->NotifyUser("", NotifyType::StatusMessage);

	Notes->Text =

		"Release notes :\n"
		"\n"
		"------------------------------------------------------\n"
		"V1.15\n"
		"*Fixed grid in Horarios Page on landscape mode.\n"
		"*Fixed elements in Welcome Page on landscape mode.\n"
		"*Minor GUI fixes.\n"
		"*Fixed transitions.\n"
		"*Changed some translations.\n"
		"*Fixed corruption in portrait mode.\n"
		"*Added loading animation on HorariosPage.\n"
		"*Fixed Grid transparencies.\n"
		"*Fixed 3D title effect on Horarios Page.\n"
		"*Now 'Legajo' and 'Fecha de consulta' are hidden until page is loaded.\n"
		"*Alerts if the content is readed from cache.\n"
		"\n"
		"Know Bugs :\n"
		"\n"
		"------------------------------------------------------\n"
		"V1.1\n"
		"*Fixed a bug that causes a crash on dekstop devices.\n"
		"*Changes and fixes in WelcomePage GUI.\n"
		"*Fixed some translations.\n"
		"*Fixed size elements on dekstop devices.\n"
		"*Fixed FooterPanel in all pages.\n"
		"*Changed all titles to new 3d look.\n"
		"*Changed all old buttons to new look 3D buttons in all pages.\n"
		"*New and redesigned ReleaseNotesPage.\n"
		"*Added animations and transitions.\n"
		"*New look at HorariosPage.\n"
		"*Fix autoscale in all pages.\n"
		"*Fixed items in HorariosPAge are note selectables.\n"
		"*Changed filenames and project name.\n"
		"\n"
		"Know Bugs :\n"
		"\n"
		"------------------------------------------------------\n"
		"V1.02\n"
		"*New and redesigned MainPage.\n"
		"*Now pages are centered correctly in landscape mode.\n"
		"*Revised and fixed translations.\n"
		"*Revised source code.\n"
		"\t - *A lot of changes and minor fixes.\n"
		"*Deleted unused code and files.\n"
		"*Fixed some wrong error messages text.\n"
		"*Updated certificates.\n"
		"*Fixed a random bug related to SuspensionManager.\n"
		"\n"
		"Know Bugs :\n"
		"\n"
		"------------------------------------------------------\n"
		"V1.01\n"
		"*Fixes in App.xaml.\n"
		"*Fixed some translations in source code.\n"
		"*Fixed bad version in Windows Store.\n"
		"*Deleted unused code.\n"
		"\n"
		"Know Bugs :\n"
		"\n"
		"------------------------------------------------------\n"
		"V1.00 (Final release)\n"
		"*Added cache offline read for no internet connection.\n"
		"*Save my last used legajo.\n"
		"*Deleted unused files.\n"
		"*Changes in source code.\n"
		"\t - Deleted unused code.\n"
		"\t - Optimized functions.\n"
		"\t - Better comments.\n"
		"*Fixed error handler for no internet connection.\n"
		"*Minor fixes on some texts.\n"
		"*Updated manifest.\n"
		"*Speed and memory improvement.\n"
		"*Changed problematic functions.\n"
		"*Fixed after suspension, can't go back from Horarios Page pressing Hardware Back Button.(bug#6161022\n"
		"*Better suspension Manager.\n"
		"\n"
		"Know Bugs :\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.91rc\n"
		"*Minor changes in source code\n"
		"*Store App Certification for Windows 10\n"
		"\n"
		"Know Bugs :\n"
		"*After suspension, can't go back from Horarios Page pressing Hardware Back Button.\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.9rp\n"
		"*Revised code.\n"
		"*Fixed minor bug in Main Page.\n"
		"*Removed unused code and reduced app size.\n"
		"*Changed some font sizes.\n"
		"*Fixed an uppercase in titles.\n"
		"*Fixed horarios don't clean up when navigating back.(#bug6161013).\n"
		"*Fixed can't exit from app.\n"
		"*Fixed Hardware Back Button bugs.(bug#6161012), (bug#6161014).\n"
		"*Fixed Error messages bugs.(bug#6161016).\n"
		"*Fixed when Hardware Back Button is pressed, the app stop working correclty.(bug#6161012).\n"
		"*Fixed if a legajo is not encountered in database it won't show an error.\n"
		"*Fixed translations.\n"
		"*Fixed random crash occurs when restoring from suspension.\n"
		"*Fixed Horarios Page are not working after pressing Hardware Back button.\n"
		"*Fixed navigation bug that occurrs under certain conditions.(bug#6161021).\n"
		"\n"
		"Know Bugs :\n"
		"\n"
		"------------------------------------------------------\n"
		"V0.87b\n"
		"*Added better handler for no internet connection.\n"
		"*A lot of changes in the source code.\n"
		"*Fixed no internet connection incorrect message.(bug#6161008).\n"
		"*Fixed Hardware Back Button bug.\n"
		"*Changes in the UI.\n"
		"\t- Fixed some misaligned objects in landscape mode.\n"
		"\t- Fixed some background colors.\n"
		"*Fixed Screen flickering when pressing Hardware Back button.\n"
		"*Fixed release notes separator.\n"
		"\n"
		"Know Bugs :\n"
		"*Loading message is not being show.\n"
		"*If a legajo is not encountered in database it won't show an error.\n"
		"*When Hardware Back Button is pressed, the app stop working correclty.(bug#6161012).\n"
		"*Random crash occurs when restoring from suspension.\n"
		"*Horarios Page are not working after pressing Hardware Back button.\n"
		"*Horarios don't clean up when navigate back.(#bug6161013).\n"
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
		"*Horarios don't clean up when navigate back.(#bug6161013).\n"
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
		"V0.1a (First release)\n"
		"(Nov / 7 / 2016)\n"
		"\n";

}

// On Click 'Hyperlinks'
void ReleaseNotesPage::Footer_Click(Object^ sender, RoutedEventArgs^ e)
{
	auto uri = ref new Uri((String^)((HyperlinkButton^)sender)->Tag);
	Windows::System::Launcher::LaunchUriAsync(uri);
}

// Navigation: Back Button
void ReleaseNotesPage::Backbutton1(Object^ sender, RoutedEventArgs^ e)
{
	rootPage->NotifyUser("", NotifyType::StatusMessage);
	Frame->Navigate(TypeName(SBX_HORARIOS::WelcomePage::typeid));
}
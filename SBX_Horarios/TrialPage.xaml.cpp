#include "pch.h"
#include "TrialPage.xaml.h"

using namespace SBX_HORARIOS;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

TrialPage::TrialPage()
{
	InitializeComponent();
}

void TrialPage::Website_Click(Object^ sender, RoutedEventArgs^ e)
{
	auto uri = ref new Uri((String^)((HyperlinkButton^)sender)->Tag);
	Windows::System::Launcher::LaunchUriAsync(uri);
}
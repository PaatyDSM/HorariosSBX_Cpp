#include "pch.h"
#include "MainPage.xaml.h"
#include "SampleConfiguration.h"

using namespace PaatyDSM;

Platform::Array<Scenario>^ MainPage::scenariosInner = ref new Platform::Array<Scenario>
{
    // The format here is the following:
    //     { "Description for the sample", "Fully qualified name for the class that implements the scenario" }
    { "Consultar", "PaatyDSM.HttpClientSample.HorariosPage" },
};

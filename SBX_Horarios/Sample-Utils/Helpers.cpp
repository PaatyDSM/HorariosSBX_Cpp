﻿#include "pch.h"

#include "Sample-Utils\Helpers.h"
#include <MainPage.xaml.h>

using namespace SBX_HORARIOS;

using namespace concurrency;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Web::Http;
using namespace Windows::Web::Http::Filters;
using namespace Windows::Web::Http::Headers;

task<HttpResponseMessage^> Helpers::DisplayTextResultAsync(
    HttpResponseMessage^ response,
    TextBox^ output)
{
    // Read content as string. We need to use use_current() with the continuations since the tasks are completed on
    // background threads and we need to run on the UI thread to update the UI.
    task<String^> readAsStringTask(response->Content->ReadAsStringAsync());

    return readAsStringTask.then([=](String^ responseBodyAsText)
	{
        // Convert all instances of <br> to newline.
        std::wstring ws = responseBodyAsText->Data();

        output->Text += ref new String(ws.c_str());

        return response;
    },
		task_continuation_context::use_current());
}


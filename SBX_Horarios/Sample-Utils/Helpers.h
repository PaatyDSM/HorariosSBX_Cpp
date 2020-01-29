#pragma once

#include "pch.h"

using namespace concurrency;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Web::Http;

namespace SBX_HORARIOS
{
	class Helpers
	{
	
	public:
		static task<HttpResponseMessage^> DisplayTextResultAsync(
			HttpResponseMessage^ response,
			TextBox^ output);
	};
}

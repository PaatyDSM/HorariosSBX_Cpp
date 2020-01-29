﻿#pragma once

#include "pch.h"

namespace PaatyDSM
{
    namespace HttpClientSample
    {
		class Helpers
		{
		public:
			static void WriteOutputText(
				Windows::UI::Xaml::Controls::Page^ page,
				Windows::UI::Xaml::Controls::TextBox^ output,
				Platform::String^ text);
			static concurrency::task<Windows::Web::Http::HttpResponseMessage^> DisplayTextResultAsync(
				Windows::Web::Http::HttpResponseMessage^ response,
				Windows::UI::Xaml::Controls::TextBox^ output);
            static Platform::String^ SerializeHeaders(
                Windows::Web::Http::HttpResponseMessage^ response);
            static Platform::String^ SerializeHeaderCollection(
                Windows::Foundation::Collections::IIterable<
                    Windows::Foundation::Collections::IKeyValuePair<Platform::String^, Platform::String^>^>^ headers);
            static Windows::Web::Http::HttpClient^ CreateHttpClient();
            static void ScenarioStarted(
                Windows::UI::Xaml::Controls::TextBox^ outputField);
            static void ReplaceQueryString(
                Windows::UI::Xaml::Controls::TextBox^ addressField,
                Platform::String^ newQueryString);
            static Platform::String^ Trim(Platform::String^ s);
            static void ReplaceAll(std::wstring& value, _In_z_ const char16* from, _In_z_ const char16* to);
            static std::wstring::size_type Helpers::IndexOf(Platform::String^ s, const wchar_t value);
            static Platform::String^ Substring(
                Platform::String^ s,
                std::wstring::size_type startIndex,
                std::wstring::size_type length);
        };
    }
}

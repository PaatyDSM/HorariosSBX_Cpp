#pragma once

#include "MainPage.g.h"
#include "SampleConfiguration.h"

namespace PaatyDSM
{
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};

	ref class StaticInfo sealed {
	public:
		property Platform::String^ sName;
	};

	/// <summary>
	/// MainPage holds the status block and frame in which scenario files are loaded.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		void HardwareButtons_BackPressed(Object^ sender, Windows::Phone::UI::Input::BackPressedEventArgs^ e);

	internal:
		static MainPage^ Current;
		void NotifyUser(Platform::String^ strMessage, NotifyType type);
	};
}

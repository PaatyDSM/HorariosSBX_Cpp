#pragma once

#include "MainPage.g.h"

using namespace Platform;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Phone::UI::Input;

namespace SBX_HORARIOS
{
	/// <summary>
	/// Enums the Status NotifyTypes.
	/// </summary>
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};

	/// <summary>
	/// MainPage contiene el Status Block y el Frame en el cual todas las páginas son cargadas.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo(NavigationEventArgs^ e) override;

	private:
		void HardwareButtons_BackPressed(Object^ sender, BackPressedEventArgs^ e);

	internal:
		static MainPage^ Current;
		void NotifyUser(String^ strMessage, NotifyType type);
	};
}

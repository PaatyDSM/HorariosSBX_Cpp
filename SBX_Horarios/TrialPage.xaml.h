#pragma once

#include "TrialPage.g.h"

using namespace Windows::UI::Xaml;

namespace SBX_HORARIOS
{
	/// <summary>
	/// Una página vacía que se puede usar de forma independiente o a la que se puede navegar dentro de un objeto Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class TrialPage sealed
	{
	public:
		TrialPage();

	private:
		void Website_Click(Platform::Object^ sender, RoutedEventArgs^ e);
	};
}

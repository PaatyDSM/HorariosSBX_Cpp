#pragma once

namespace SDKSample
{
    namespace Json
    {
        // Mark as WebHostHidden since Windows.Data.Json API is not available in JavaScript.
        [Windows::Foundation::Metadata::WebHostHidden]
        [Windows::UI::Xaml::Data::Bindable]
        public ref class School sealed
        {
        public:
            School(void);
            School(Windows::Data::Json::JsonObject^ jsonObject);

            property Platform::String^ Fecha
            {
                Platform::String^ get();
                void set(Platform::String^ value);
            }

            property Platform::String^ HoraEntrada
            {
                Platform::String^ get();
                void set(Platform::String^ value);
            }

            property Platform::String^ HoraSalida
            {
                Platform::String^ get();
                void set(Platform::String^ value);
            }

			property Platform::String^ Tienda
			{
				Platform::String^ get();
				void set(Platform::String^ value);
			}

        private:
            static Platform::String^ fechaKey;
            static Platform::String^ horaEntradaKey;
            static Platform::String^ horaSalidaKey;
			static Platform::String^ tiendaKey;
			static Platform::String^ asignacionesKey;

            Platform::String^ fecha;
            Platform::String^ horaEntrada;
            Platform::String^ horaSalida;
			Platform::String^ tienda;
        };
    }
}

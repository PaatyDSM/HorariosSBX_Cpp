//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
//*********************************************************

#pragma once

#include "School.h"

namespace SDKSample
{
    namespace Json
    {
        // Mark as WebHostHidden since School is WebHostHidden.
        [Windows::Foundation::Metadata::WebHostHidden]
        [Windows::UI::Xaml::Data::Bindable]
        public ref class User sealed
        {
        public:
            User(void);
            User(Platform::String^ jsonString);

            property Platform::String^ Legajo
            {
                Platform::String^ get();
                void set(Platform::String^ value);
            }

            property Platform::String^ FechaConsulta
            {
                Platform::String^ get();
                void set(Platform::String^ value);
            }

            property Windows::Foundation::Collections::IVector<SDKSample::Json::School^>^ Asignaciones
            {
                Windows::Foundation::Collections::IVector<SDKSample::Json::School^>^ get();
            }

        private:
            static Platform::String^ legajoKey;
            static Platform::String^ fechaConsultaKey;
            static Platform::String^ asignacionesKey;

            Platform::String^ legajo;
            Platform::String^ fechaConsulta;
            Platform::Collections::Vector<School^>^ asignaciones;
        };
    }
}

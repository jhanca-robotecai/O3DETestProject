
#pragma once

#include <AzCore/Component/Component.h>

#include <JHO3DETestProject/JHO3DETestProjectBus.h>

namespace JHO3DETestProject
{
    class JHO3DETestProjectSystemComponent
        : public AZ::Component
        , protected JHO3DETestProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(JHO3DETestProjectSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        JHO3DETestProjectSystemComponent();
        ~JHO3DETestProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // JHO3DETestProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}

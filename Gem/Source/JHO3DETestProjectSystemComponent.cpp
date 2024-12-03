
#include <AzCore/Serialization/SerializeContext.h>

#include "JHO3DETestProjectSystemComponent.h"

#include <JHO3DETestProject/JHO3DETestProjectTypeIds.h>

namespace JHO3DETestProject
{
    AZ_COMPONENT_IMPL(JHO3DETestProjectSystemComponent, "JHO3DETestProjectSystemComponent",
        JHO3DETestProjectSystemComponentTypeId);

    void JHO3DETestProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<JHO3DETestProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void JHO3DETestProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("JHO3DETestProjectService"));
    }

    void JHO3DETestProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("JHO3DETestProjectService"));
    }

    void JHO3DETestProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void JHO3DETestProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    JHO3DETestProjectSystemComponent::JHO3DETestProjectSystemComponent()
    {
        if (JHO3DETestProjectInterface::Get() == nullptr)
        {
            JHO3DETestProjectInterface::Register(this);
        }
    }

    JHO3DETestProjectSystemComponent::~JHO3DETestProjectSystemComponent()
    {
        if (JHO3DETestProjectInterface::Get() == this)
        {
            JHO3DETestProjectInterface::Unregister(this);
        }
    }

    void JHO3DETestProjectSystemComponent::Init()
    {
    }

    void JHO3DETestProjectSystemComponent::Activate()
    {
        JHO3DETestProjectRequestBus::Handler::BusConnect();
    }

    void JHO3DETestProjectSystemComponent::Deactivate()
    {
        JHO3DETestProjectRequestBus::Handler::BusDisconnect();
    }
}

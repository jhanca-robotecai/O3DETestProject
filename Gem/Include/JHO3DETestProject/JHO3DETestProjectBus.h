
#pragma once

#include <JHO3DETestProject/JHO3DETestProjectTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace JHO3DETestProject
{
    class JHO3DETestProjectRequests
    {
    public:
        AZ_RTTI(JHO3DETestProjectRequests, JHO3DETestProjectRequestsTypeId);
        virtual ~JHO3DETestProjectRequests() = default;
        // Put your public methods here
    };

    class JHO3DETestProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using JHO3DETestProjectRequestBus = AZ::EBus<JHO3DETestProjectRequests, JHO3DETestProjectBusTraits>;
    using JHO3DETestProjectInterface = AZ::Interface<JHO3DETestProjectRequests>;

} // namespace JHO3DETestProject

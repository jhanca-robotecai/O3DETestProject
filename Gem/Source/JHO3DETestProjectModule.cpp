
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "JHO3DETestProjectSystemComponent.h"

#include <JHO3DETestProject/JHO3DETestProjectTypeIds.h>

namespace JHO3DETestProject
{
    class JHO3DETestProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(JHO3DETestProjectModule, JHO3DETestProjectModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(JHO3DETestProjectModule, AZ::SystemAllocator);

        JHO3DETestProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                JHO3DETestProjectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<JHO3DETestProjectSystemComponent>(),
            };
        }
    };
}// namespace JHO3DETestProject

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), JHO3DETestProject::JHO3DETestProjectModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_JHO3DETestProject, JHO3DETestProject::JHO3DETestProjectModule)
#endif

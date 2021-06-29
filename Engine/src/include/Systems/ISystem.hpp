#pragma once
#include <memory>
namespace EternalEngine
{
    class ISystem
    {
    public:
        ISystem() = default;
        ~ISystem() = default;
        virtual const char *name() = 0;
        virtual void update(float delta) = 0;
    };
    #define REGISTER_SYSTEM(name) static ISystem *create_new_##name() { return new name(); } static const bool system_added_##name = SystemManager::get_singleton().add_system(#name, std::function<ISystem *()>(create_new_##name))
};

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
};

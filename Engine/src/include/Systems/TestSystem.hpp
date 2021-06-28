#pragma once

#include "ISystem.hpp"
#include "SystemManager.hpp"

namespace EternalEngine
{
    class TestSystem : public ISystem
    {
    public:
        const char *name() override { return "TestSystem"; }
        void update(float delta) override;
    };
    REGISTER_SYSTEM(TestSystem);
};

#pragma once

#include <Components/MeshComponent.hpp>
#include <memory>
#include <vector>
namespace EternalEngine
{
    class MeshUtils
    {
        public:
            static int CreateMesh(std::shared_ptr<MeshComponent> mesh,const float *vertices, unsigned int vertices_count, const unsigned int *indices,unsigned int indices_count);
            static void ClearMesh();
    };
}
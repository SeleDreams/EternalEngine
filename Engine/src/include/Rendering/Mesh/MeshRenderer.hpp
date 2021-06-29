#pragma once
#include <memory>
namespace EternalEngine
{
    class MeshRenderer
    {
        public:
            static int CreateMesh(std::shared_ptr<class Mesh> mesh,const float *vertices, unsigned int vertices_count, const unsigned int *indices,unsigned int indices_count);
            static void ClearMesh(std::shared_ptr<class Mesh> mesh);
    };
}
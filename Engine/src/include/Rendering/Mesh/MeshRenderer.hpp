#pragma once
#include <Rendering/Mesh/Mesh.hpp>
#include <Components/ShaderComponent.hpp>
#include <memory>
#include <iostream>

namespace EternalEngine
{
    class MeshRenderer
    {
    public:
        static int CreateMesh(Mesh &mesh, const float *vertices, unsigned int vertices_count, const unsigned int *indices, unsigned int indices_count);
        static void ClearMesh(Mesh &mesh);
        static void CreateShader(ShaderComponent &shader, std::string vert_shader, std::string frag_shader);
    };
}
#version 330

layout (location = 0) in vec3 pos;

uniform mat4 xModel;
uniform mat4 xProjection;
out vec4 vColour;
void main()
{
    gl_Position = xProjection * xModel * vec4(pos.x,pos.y,pos.z,1.0);
    vColour = vec4(clamp(pos,0.0f,1.0f),1.0f);
}
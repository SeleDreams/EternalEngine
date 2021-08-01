#version 330

layout (location = 0) in vec3 pos;

uniform mat4 xTransform;
uniform mat4 xProjection;
uniform mat4 xViewMatrix;

out vec4 vColour;
void main()
{
    gl_Position = xProjection * xViewMatrix * xTransform * vec4(pos.x,pos.y,pos.z,1.0);
    vColour = vec4(clamp(pos,0.0f,1.0f),1.0f);
}
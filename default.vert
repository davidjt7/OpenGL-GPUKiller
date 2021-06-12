#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 color;

uniform float scale;
uniform float translateX;
uniform float translateY;
uniform float translateZ;

void main()
{
   gl_Position = vec4((aPos.x * scale) + translateX, (aPos.y * scale) + translateY, (aPos.z * scale) + translateZ, 1.0);
   color = aColor;
}
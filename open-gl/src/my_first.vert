#version 330 core

layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec2 aTexCoord;

out vec3 vPos;
out vec3 vColor;
out vec2 TexCoord;

void main()
{
    vPos = aPos;
    vColor = aColor;
    TexCoord = aTexCoord;
    gl_Position = vec4(aPos.xyz, 1.0);
}
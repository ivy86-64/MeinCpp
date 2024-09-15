#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform float offsetx;

out vec3 ourColor;

void main()
{
   gl_Position = vec4(  offsetx + aPos.x - 0.5f,
                        aPos.y,
                        aPos.z,
                        1.0);
   ourColor = aColor;
}
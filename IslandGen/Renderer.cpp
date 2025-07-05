#include "Renderer.h"

std::string vertShader = R"V0(

#version 330 core
layout(location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}

)V0";

std::string fragShader = R"V0(

#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
} 

)V0";

void Renderer::Render() {
    m_Shader.UseProgram();
    m_Island.Draw();
}

Renderer::Renderer() : m_Shader(vertShader, fragShader), m_Island() {

}
#pragma once

#include <glad/glad.h>

#include <vector>

class IslandMesh
{
private:
	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_EBO;

public:
	void Draw();

	IslandMesh(std::vector<float>& vertices, std::vector<unsigned int> indices);
};


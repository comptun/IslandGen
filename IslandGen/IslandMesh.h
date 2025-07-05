#pragma once

#include <glad/glad.h>

class IslandMesh
{
private:
	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_EBO;

public:
	void Draw();

	IslandMesh();
};


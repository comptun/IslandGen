#pragma once

#include "Shader.h"
#include "IslandMesh.h"

class Renderer
{
private:
	Shader m_Shader;
	IslandMesh m_Island;

public:

	void Render();

	Renderer();
};


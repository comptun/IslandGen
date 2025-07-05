#pragma once

#include "Shader.h"
#include "Island.h"

class Renderer
{
private:
	Shader m_Shader;
	Island m_Island;

public:

	void Render();

	Renderer();
};


#pragma once

#include <glm/glm.hpp>
#include <memory>

#include "LuauRandom.h"
#include "IslandMesh.h"

class Island
{
private:
	std::unique_ptr<IslandMesh> m_Island;
public:
	void CreateIslandPart(LuauRandom ChunkRandom, glm::ivec2 Position, int Radius, int ControlCount, float Noise);
	void CreateIsland(glm::ivec2 Position);
	Island();
};


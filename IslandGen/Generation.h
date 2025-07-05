#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "LuauRandom.h"

std::vector<glm::vec2> generateNoisyCirclePoints3D(LuauRandom& ChunkRandom, glm::ivec2& center, float radius, int count, float noiseFactor);
std::vector<glm::vec2> generateLoopPath3D(std::vector<glm::vec2>& controlPoints, int segmentsPerCurve, glm::ivec2& center);
int HashSpiral(int x, int y);
glm::ivec2 CoordFromIndex(int n);


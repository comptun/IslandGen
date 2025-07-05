#include "Island.h"

#include "Generation.h"
#include "earcut.hpp"

void Island::CreateIslandPart(LuauRandom ChunkRandom, glm::ivec2 Position, int Radius, int ControlCount, float Noise) {
	std::vector<glm::vec2> controlPoints = generateNoisyCirclePoints3D(ChunkRandom, Position, Radius, ControlCount, Noise);
	std::vector<glm::vec2> loopPath = generateLoopPath3D(controlPoints, ChunkRandom.NextInteger(1, 3), Position);

	//using Coord = float;

	//// The index type. Defaults to uint32_t, but you can also pass uint16_t if you know that your
	//// data won't have more than 65536 vertices.
	//using N = uint32_t;

	//// Create array
	//using Point = std::array<Coord, 2>;
	//std::vector<std::vector<Point>> polygon;

	//std::vector<Point> points;
	//for (int i = 0; i < loopPath.size(); i++) {
	//	//points.push_back(Point( { loopPath[i].x, loopPath[i].y }));
	//}
}

void Island::CreateIsland(glm::ivec2 Position) {
	LuauRandom ChunkRandom(HashSpiral(Position.x, Position.y) + 1234);

	ChunkRandom.NextNumber();
	ChunkRandom.NextNumber();
	ChunkRandom.NextNumber();

	int Radius = 600;

	CreateIslandPart(ChunkRandom, Position, Radius, 10, 0.4);
}

Island::Island() {

}
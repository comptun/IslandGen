#include "Generation.h"

#include <numbers>
#include <cmath>

//Catmull - Rom interpolation for scalars
float interpolate(float a, float b, float c, float d, float t) {
	float  t2 = t * t;
	float  t3 = t2 * t;
	return 0.5 * ((2 * b) + (-a + c) * t + (2 * a - 5 * b + 4 * c - d) * t2 + (-a + 3 * b - 3 * c + d) * t3);
}

//Catmull - Rom interpolation for Vector3(x and z), y is fixed
glm::vec2 catmullRom3D(glm::vec2& p0, glm::vec2& p1, glm::vec2& p2, glm::vec2& p3, float t, glm::ivec2& center) {
	float x = interpolate(p0.x, p1.x, p2.x, p3.x, t);
	float y = interpolate(p0.y, p1.y, p2.y, p3.y, t);
	return glm::vec2(x, y);
}

//Generate randomized control points in a ring
std::vector<glm::vec2> generateNoisyCirclePoints3D(LuauRandom& ChunkRandom, glm::ivec2& center, float radius, int count, float noiseFactor) {
	std::vector<glm::vec2> points = {};
	for (int i = 1; i <= count; i++) {
		float angle = 2 * std::numbers::pi * (i - 1) / count;
		float r = radius * (1 - noiseFactor + ChunkRandom.NextNumber(0, 1) * noiseFactor * 2);
		float x = center.x + r * std::cos(angle);
		float y = center.y + r * std::sin(angle);
		points.push_back({ x, y });
	}
	return points;
}

//Generate loop path from control points
std::vector<glm::vec2> generateLoopPath3D(std::vector<glm::vec2>& controlPoints, int segmentsPerCurve, glm::ivec2& center) {
	int numPoints = controlPoints.size();
	std::vector<glm::vec2> loopPoints = {};
	int gridSize = 10;

	for (int i = 1; i <= numPoints; i++) {
		glm::vec2 p0 = controlPoints[(i - 2) % numPoints + 1];
		glm::vec2 p1 = controlPoints[(i - 1) % numPoints + 1];
		glm::vec2 p2 = controlPoints[i % numPoints + 1];
		glm::vec2 p3 = controlPoints[(i + 1) % numPoints + 1];

		for (int j = 0; j <= segmentsPerCurve - 1; j++) {
			float t = j / segmentsPerCurve;
			glm::vec2 pt = catmullRom3D(p0, p1, p2, p3, t, center);
			loopPoints.push_back(pt);
		}
	}
	return loopPoints;
}




int HashSpiral(int x, int y) {
    int ax = std::abs(x);
    int ay = std::abs(y);

    int loop = std::max(ax, ay);
    int edgelen = 2 * loop;
    int prev = (edgelen - 1) * (edgelen - 1);

    if (x == loop && y > -loop) {
        return prev + y - (-loop + 1);
    }

    if (y == loop) {
        return prev + loop - x + edgelen - 1;
    }

    if (x == -loop) {
        return prev + loop - y + 2 * edgelen - 1;
    }

    if (y == -loop) {
        return prev + x + loop + 3 * edgelen - 1;
    }

    return -1; // Shouldn't reach here
}

glm::ivec2 CoordFromIndex(int n) {

    if (n == 1) {
        return { 0,0 };
    }

    int k = 0;
    while ((2 * k + 1) * (2 * k + 1) < n) {
        k += 1;
    }

    int prev_layer_max = 0;
    if (k > 0) {
        prev_layer_max = (2 * (k - 1) + 1) * (2 * (k - 1) + 1);
    }

    int offset = n - prev_layer_max - 1;
    int side_length = 2 * k;

    int x, y;
    if (offset < side_length) {
        x = k;
        y = -k + 1 + offset;
    }
    else if (offset < 2 * side_length) {
        x = k - 1 - (offset - side_length);
        y = k;
    }
    else if (offset < 3 * side_length) {
        x = -k;
        y = k - 1 - (offset - 2 * side_length);
    }
    else {
        x = -k + 1 + (offset - 3 * side_length);
        y = -k;
    }

    return { x,y };
}
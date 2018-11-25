#pragma once

#include <cmath>
#include "Image.hpp"

struct Position {
    int X;
    int Y;
};

void drawHilbertCurve (int order, Image& img);

Position drawUpwardsSegment (Position startPos, int order, Image& img, int segmentLength);
Position drawDownwardsSegment (Position startPos, int order, Image& img, int segmentLength);
Position drawLeftwardsSegment (Position startPos, int order, Image& img, int segmentLength);
Position drawRightwardsSegment (Position startPos, int order, Image& img, int segmentLength);

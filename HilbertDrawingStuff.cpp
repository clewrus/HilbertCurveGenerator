#include "HilbertDrawingStuff.hpp"

Position drawRightwardsSegment (Position startPos, int order, Image& img, int segmentLength) {
    if (order == 0) return startPos;

    startPos = drawDownwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X + segmentLength, startPos.Y);
    startPos.X += segmentLength;

    startPos = drawRightwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X, startPos.Y - segmentLength);
    startPos.Y -= segmentLength;

    startPos = drawRightwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X - segmentLength, startPos.Y);
    startPos.X -= segmentLength;

    startPos = drawUpwardsSegment(startPos, order - 1, img, segmentLength);

    return startPos;
}

Position drawUpwardsSegment (Position startPos, int order, Image& img, int segmentLength) {
    if (order == 0) return startPos;

    startPos = drawLeftwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X, startPos.Y + segmentLength);
    startPos.Y += segmentLength;

    startPos = drawUpwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X - segmentLength, startPos.Y);
    startPos.X -= segmentLength;

    startPos = drawUpwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X, startPos.Y - segmentLength);
    startPos.Y -= segmentLength;

    startPos = drawRightwardsSegment(startPos, order - 1, img, segmentLength);

    return startPos;
}

Position drawDownwardsSegment (Position startPos, int order, Image& img, int segmentLength) {
    if (order == 0) return startPos;

    startPos = drawRightwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X, startPos.Y - segmentLength);
    startPos.Y -= segmentLength;

    startPos = drawDownwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X + segmentLength, startPos.Y);
    startPos.X += segmentLength;

    startPos = drawDownwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X, startPos.Y + segmentLength);
    startPos.Y += segmentLength;

    startPos = drawLeftwardsSegment(startPos, order - 1, img, segmentLength);

    return startPos;
}

Position drawLeftwardsSegment (Position startPos, int order, Image& img, int segmentLength){
    if (order == 0) return startPos;

    startPos = drawUpwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X - segmentLength, startPos.Y);
    startPos.X -= segmentLength;

    startPos = drawLeftwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X, startPos.Y + segmentLength);
    startPos.Y += segmentLength;

    startPos = drawLeftwardsSegment(startPos, order - 1, img, segmentLength);

    img.drawLine(startPos.X, startPos.Y, startPos.X + segmentLength, startPos.Y);
    startPos.X += segmentLength;

    startPos = drawDownwardsSegment(startPos, order - 1, img, segmentLength);

    return startPos;
}

void drawHilbertCurve (int order, Image& img) {
    int numOfSegments = std::pow(2, order) - 1;
    int segmentLength = int(std::min(img.getHeight() - 1, img.getWidth() - 1) / float(numOfSegments));

    int offsetX = (img.getWidth() - segmentLength * numOfSegments) / 2;
    int offsetY = (img.getHeight() - segmentLength * numOfSegments) / 2;

    Position startPos {offsetX, img.getHeight() - offsetY};
    drawDownwardsSegment(startPos, order, img, segmentLength);
}

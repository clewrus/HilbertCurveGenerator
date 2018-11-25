#include <iostream>
#include <cmath>
#include "Image.hpp"
#include "HilbertDrawingStuff.hpp"

int main() {
    Image img (600, 600);
    drawHilbertCurve(7, img);
    img.saveToFile("Hilbert1.ppm");

    return 0;
}

#pragma once
#include <fstream>
#include <string>
#include <exception>

class Image {
public:
    Image (unsigned int width, unsigned int height);
    void setPixel (unsigned int x, unsigned int y, bool value);
    bool getPixel (unsigned int x, unsigned int y);
    unsigned int getWidth();
    unsigned int getHeight();

    void drawLine (int x1, int y1, int x2, int y2);

    void saveToFile (std::string fileName);

    ~Image();
private:
    bool dotOnImage (int x, int y);

    bool* imageData;
    unsigned int width;
    unsigned int height;
};

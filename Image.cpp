#include "Image.hpp"

Image::Image (unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    this->imageData = new bool[width * height];

    for (unsigned int i = 0; i < width * height; i++){
        imageData[i] = false;
    }
}

void Image::setPixel (unsigned int x, unsigned int y, bool value) {
    if (x > width || y > height){
        throw std::exception();
    }

    imageData[y * width + x] = value;
}

bool Image::getPixel (unsigned int x, unsigned int y) {
    if (x > width || y > height){
        throw std::exception();
    }

    return imageData[y * width + x];
}

unsigned int Image::getWidth() {
    return width;
}
unsigned int Image::getHeight() {
    return height;
}

void Image::drawLine(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        if (y2 < y1) {
            std::swap(y2, y1);
        }
        for (int y = y1; y <= y2; y++) {
            if (dotOnImage(x1, y)) {
                setPixel(x1, y, true);
            }
        }
    }

    if (x2 < x1) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    for (int x = x1; x <= x2; x++) {
        int y = int (y1 + x * float(y2 - y1) / float (x2 - x1));
        if (dotOnImage(x, y)) {
            setPixel(x, y, true);
        }
    }

}

bool Image::dotOnImage(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}


void Image::saveToFile (std::string fileName) {
    std::ofstream file(fileName);
    file << "P3 " << width << " " << height << " 1\n";
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            if (!imageData[y * width + x]) {
                file << "1 1 1\t";
            } else {
                file << "0 0 0\t";
            }
        }
        file << "\n";
    }
}

Image::~Image() {
    delete[] imageData;
}

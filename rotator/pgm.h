#ifndef PGM_H
#define PGM_H

#include <string>
#include <vector>

#include "grayPixel.h"

class Pgm {
   private:
    int magicNum, maxVal, width, height;
    std::vector<GrayPixel> pixels;

   public:
    Pgm();
    Pgm(int magicNum, int maxVal, int width, int height,
        std::vector<GrayPixel> pixels);

    int getMagicNum() { return magicNum; };
    int getMaxVal() { return maxVal; };
    int getWidth() { return width; };
    int getHeight() { return height; };
    std::vector<GrayPixel> getPixels() { return pixels; };

    void setMagicNum(int magicNum) { this->magicNum = magicNum; };
    void setMaxVal(int maxVal) { this->maxVal = maxVal; };
    void setWidth(int width) { this->width = width; };
    void setHeight(int height) { this->height = height; };
    void setPixels(std::vector<GrayPixel> pixels) { this->pixels = pixels; };

    ~Pgm();
};

#endif
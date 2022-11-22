#include "colorPixel.h"

ColorPixel::ColorPixel() {
    r = 0;
    g = 0;
    b = 0;
}

ColorPixel::ColorPixel(unsigned char r, unsigned char g, unsigned char b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

ColorPixel::ColorPixel(const ColorPixel &rhs) {
    this->r = rhs.r;
    this->g = rhs.g;
    this->b = rhs.b;
}
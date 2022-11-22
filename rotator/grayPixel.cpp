#include "grayPixel.h"

GrayPixel::GrayPixel() { br = 0; }

GrayPixel::GrayPixel(unsigned char br) { this->br = br; }

GrayPixel::GrayPixel(const GrayPixel &rhs) { this->br = rhs.br; }
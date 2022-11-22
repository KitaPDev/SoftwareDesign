#ifndef COLORPIXEL_H
#define COLORPIXEL_H

class ColorPixel {
   private:
    unsigned char r, g, b;

   public:
    ColorPixel();
    ColorPixel(unsigned char r, unsigned char g, unsigned char b);
    ColorPixel(const ColorPixel &rhs);

    unsigned char getR() { return r; };
    unsigned char getG() { return g; };
    unsigned char getB() { return b; };

    void setR(unsigned char r) { this->r = r; };
    void setG(unsigned char g) { this->g = g; };
    void setB(unsigned char b) { this->b = b; };
};

#endif
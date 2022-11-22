#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H

class GrayPixel {
   private:
    unsigned char br;

   public:
    GrayPixel();
    GrayPixel(unsigned char br);
    GrayPixel(const GrayPixel &rhs);

    unsigned char getBr() { return br; };

    void setBr(unsigned char br) { this->br = br; };
};

#endif
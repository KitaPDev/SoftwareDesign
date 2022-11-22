#ifndef ROTATOR_H
#define ROTATOR_H

#include "pgm.h"
#include "ppm.h"

class Rotator {
   private:
    static Rotator* instance;

    Rotator(){};

   public:
    static Rotator* getInstance() {
        if (!instance) instance = new Rotator();
        return instance;
    };

    void rotate(Ppm* input, Ppm* output, int degrees);
    void rotate(Pgm* input, Pgm* output, int degrees);

    ~Rotator();
};

#endif
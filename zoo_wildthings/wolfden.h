/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef WOLFDEN_H
#define WOLFDEN_H

#include <string>
#include <vector>

#include "wolf.h"
#include "zoo.h"

class WolfDen : public Zoo {
   private:
    static WolfDen* instance;

    WolfDen(){};

   public:
    static WolfDen* getInstance() {
        if (!instance) instance = new WolfDen();
        return instance;
    }

    virtual std::shared_ptr<Animal> create() {
        return std::make_shared<Wolf>();
    }

    ~WolfDen() {
        delete instance;
    }
};

#endif
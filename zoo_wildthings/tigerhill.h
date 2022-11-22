/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef TIGERHILL_H
#define TIGERHILL_H

#include <string>
#include <vector>

#include "tiger.h"
#include "zoo.h"

class TigerHill : public Zoo {
   private:
    static TigerHill* instance;

    TigerHill(){};

   public:
    static TigerHill* getInstance() {
        if (!instance) instance = new TigerHill();
        return instance;
    }

    virtual std::shared_ptr<Animal> create() {
        return std::make_shared<Tiger>();
    }

    ~TigerHill() {
        delete instance;
    }
};

#endif
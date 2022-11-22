/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef SERPENTLAIR_H
#define SERPENTLAIR_H

#include <string>
#include <vector>

#include "serpent.h"
#include "zoo.h"

class SerpentLair : public Zoo {
   private:
    static SerpentLair* instance;

    SerpentLair(){};

   public:
    static SerpentLair* getInstance() {
        if (!instance) instance = new SerpentLair();
        return instance;
    }

    virtual std::shared_ptr<Animal> create() {
        return std::make_shared<Serpent>();
    }

    ~SerpentLair() {
        delete instance;
    }
};

#endif
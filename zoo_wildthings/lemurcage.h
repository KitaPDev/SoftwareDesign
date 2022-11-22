/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef LEMURCAGE_H
#define LEMURCAGE_H

#include <string>
#include <vector>

#include "lemur.h"
#include "zoo.h"

class LemurCage : public Zoo {
   private:
    static LemurCage* instance;

    LemurCage(){};

   public:
    static LemurCage* getInstance() {
        if (!instance) instance = new LemurCage();
        return instance;
    }

    virtual std::shared_ptr<Animal> create() {
        return std::make_shared<Lemur>();
    }

    ~LemurCage() {
        delete instance;
    }
};

#endif
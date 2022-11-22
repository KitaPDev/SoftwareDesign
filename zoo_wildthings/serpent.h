/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef SERPENT_H
#define SERPENT_H

#include "animal.h"

class Serpent : public Animal {
   public:
    virtual std::string introduce() const override {
        return "I am a serpent, my name is " + this->name + ", I hiss and I eat mice.\n";
    }

    std::shared_ptr<Animal> clone() const override {
        return std::make_shared<Serpent>(*this);
    }
};

#endif
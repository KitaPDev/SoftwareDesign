/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef WOLF_H
#define WOLF_H

#include "animal.h"

class Wolf : public Animal {
   public:
    virtual std::string introduce() const override {
        return "I am a wolf, my name is " + this->name + ", I growl, and I eat chicken.\n";
    }

    std::shared_ptr<Animal> clone() const override {
        return std::make_shared<Wolf>(*this);
    }
};

#endif
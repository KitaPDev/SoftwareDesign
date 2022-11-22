/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef LEMUR_H
#define LEMUR_H

#include "animal.h"

class Lemur : public Animal {
   public:
    virtual std::string introduce() const override {
        return "I am a lemur, my name is " + this->name + ", I squeak, and I eat fruit.\n";
    }

    std::shared_ptr<Animal> clone() const override {
        return std::make_shared<Lemur>(*this);
    }
};

#endif
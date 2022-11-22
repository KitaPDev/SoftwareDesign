/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef KANGAROO_H
#define KANGAROO_H

#include "animal.h"

class Kangaroo : public Animal {
   public:
    virtual std::string introduce() const override {
        return "I am a kangaroo, my name is " + this->name + ", I click, and I eat carrots.\n";
    }

    std::shared_ptr<Animal> clone() const override {
        return std::make_shared<Kangaroo>(*this);
    }
};

#endif
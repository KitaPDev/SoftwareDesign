/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef TIGER_H
#define TIGER_H

#include <string>
#include <vector>

#include "animal.h"

class Tiger : public Animal {
   public:
    virtual std::string introduce() const override {
        return "I am a tiger, my name is " + this->name + ", I roar, and I eat meat.\n";
    }

    std::shared_ptr<Animal> clone() const override {
        return std::make_shared<Tiger>(*this);
    }
};

#endif
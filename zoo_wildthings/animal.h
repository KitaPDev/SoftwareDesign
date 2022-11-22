/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <memory>

class Animal {
   protected:
    std::string name;

   public:
    virtual std::string introduce() const = 0;
    virtual std::shared_ptr<Animal> clone() const = 0;
    virtual ~Animal() = default;

    void setName(const std::string& name) {
        this->name = name;
    }
};

#endif
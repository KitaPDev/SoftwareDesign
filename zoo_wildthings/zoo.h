/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <vector>

#include "animal.h"

class Zoo {
   public:
    virtual std::shared_ptr<Animal> create() = 0;
};

#endif
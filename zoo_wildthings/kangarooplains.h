/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#ifndef KANGAROOPLAINS_H
#define KANGAROOPLAINS_H

#include <string>
#include <vector>

#include "kangaroo.h"
#include "zoo.h"

class KangarooPlains : public Zoo {
   private:
    static KangarooPlains* instance;

    KangarooPlains(){};

   public:
    static KangarooPlains* getInstance() {
        if (!instance) instance = new KangarooPlains();
        return instance;
    }

    virtual std::shared_ptr<Animal> create() {
        return std::make_shared<Kangaroo>();
    }

    ~KangarooPlains() {
        delete instance;
    }
};

#endif
#ifndef __REFINER_H__
#define __REFINER_H__

#include <unordered_map>

#include "legalResult.h"
#include "rectilinear.h"
#include "floorplan.h"

class Refiner{
public:
    Floorplan *fp;
    std::unordered_map<Rectilinear *, Cord> optimalCentre;

    Refiner(LegalResult lr);
    Refiner(Floorplan *legalFP);
    Refiner(const Refiner &other);
    ~Refiner()

}


#endif // __REFINER_H__
#include "units.h"

std::ostream &operator << (std::ostream &os, const direction1D &w){
    if(w == direction1D::CLOCKWISE) os << "direction1D::CLOCKWISE";
    else os << "direction1D::COUNTERCLOCKWISE";

    return os;
}

std::ostream &operator << (std::ostream &os, const orientation2D &o){
    if(o == orientation2D::HORIZONTAL) os << "orientation2D::HORIZONTAL";
    else os << "orientation2D::VERTICAL";

    return os;
}
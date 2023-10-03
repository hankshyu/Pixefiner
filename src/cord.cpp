#include "cord.h"

Cord::Cord(len_t x_in, len_t y_in)
    : x(x_in), y(y_in) {}

Cord Cord::operator+(const Cord &addend) const {
    return Cord(x + addend.x, y + addend.y);
}

Cord Cord::operator-(const Cord &subtrahend) const {
    return Cord(x - subtrahend.x, y - subtrahend.y);
}

Cord Cord::operator*(const len_t &scalar) const {
    return Cord(scalar * x, scalar * y);
}

Cord Cord::operator/(const len_t &scalar) const {
    return Cord(x/scalar, y/scalar);
}

bool Cord::operator==(const Cord &comp) const {
    return ((x == comp.x) && (y == comp.y));
}

bool Cord::operator!=(const Cord &comp) const {
    return ((x != comp.x) || (y != comp.y));
}

bool Cord::operator<(const Cord &comp) const {
    return (x < comp.x) || ((x == comp.x) && (y < comp.y));
}

size_t std::hash<Cord>::operator()(const Cord &key) const {
    return (std::hash<len_t>()(key.x)) ^ (std::hash<len_t>()(key.y));
}

std::ostream &operator<<(std::ostream &os, const Cord &c) {
    os << "(" << c.x << ", " << c.y << ")";
    return os;
}

std::ostream &operator<<(std::ostream &os, const mCord &c) {
    os << "(" << c.x() << ", " << c.y() << ")";
    return os;
}
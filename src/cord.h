#ifndef __CORD_H__
#define __CORD_H__

#include <ostream>
#include "units.h"

struct Cord
{
public:
    len_t x;
    len_t y;

    Cord(len_t x_in, len_t y_in);

    Cord operator+(const Cord &addend) const;
    Cord operator-(const Cord &subtrahend) const;
    Cord operator*(const len_t &scalar) const;
    Cord operator/(const len_t &scalar) const;

    bool operator==(const Cord &comp) const;
    bool operator!=(const Cord &comp) const;

    bool operator<(const Cord &comp) const;

    friend std::ostream &operator << (std::ostream &os, const Cord &c);
};

std::ostream &operator << (std::ostream &os, const Cord &c);

#endif // #define __CORD_H__
#ifndef __UNITS_H__
#define __UNITS_H__

#include <cstdint>
#include <limits.h>
#include <ostream>


#include "boost/polygon/polygon.hpp"

typedef int32_t len_t;
typedef int64_t  area_t;

typedef double flen_t;
typedef double angle_t;

// enum direction_1d_enum {LOW = 0, HIGH = 1,
//                         LEFT = 0, RIGHT = 1,
//                         CLOCKWISE = 0, COUNTERCLOCKWISE = 1,
//                         REVERSE = 0, FORWARD = 1,
//                         NEGATIVE = 0, POSITIVE = 1 };
typedef boost::polygon::direction_1d_enum direction1D;
std::ostream &operator << (std::ostream &os, const direction1D &d);

// enum orientation_2d_enum { HORIZONTAL = 0, VERTICAL = 1 };
typedef boost::polygon::orientation_2d_enum orientation2D;
std::ostream &operator << (std::ostream &os, const orientation2D &o);

#define LEN_T_MAX std::numeric_limits<len_t>::max()
#define LEN_T_MIN std::numeric_limits<len_t>::min()

#define FLEN_T_MAX std::numeric_limits<flen_t>::max()
#define FLEN_T_MIN std::numeric_limits<flen_t>::min()

#define AREA_T_MAX std::numeric_limits<area_t>::max()
#define AREA_T_MIN std::numeric_limits<area_t>::min()



#endif // __UNITS_H__
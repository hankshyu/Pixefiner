#ifndef __LINE_H__
#define __LINE_H__

#include <ostream>

#include "boost/polygon/polygon.hpp"
#include "units.h"
#include "cord.h"

// struct Interval{
//     Cord low;
//     Cord high;
//     direction1D direction;

// };
// // TODO
// namespace boost{ namespace polygon{
//     template<>
//     struct geometry_concept<Interval> {typedef segment_concept type;};

//     template <typename Segment>
//     struct interval_traits{
//         typedef typename Segment::coordinate_type len_t;
//         typedef typename Segment::point_type Cord;

//         static inline point_type get(const Segment& segment, direction1D dir) {
//             if(dir == direction1D::LOW) return segment.low;
//             else return segment.high;
//         }
//     };

//     template <typename Segment>
//     struct segment_mutable_traits{
//         typedef typename segment_traits<Segment>::coordinate_type len_t;
//         typedef typename segment_traits<Segment>::point_type Cord;

//         static inline void set(Segment& segment, direction1D dir, const point_type& point) {
//             segment.set(dir, p);
//         }

//         static inline Segment construct(const point_type& low, const point_type& high) {
//             if(low.x() == high.x()){
//                 return (low.y < high.y)? Segment(low, high) : Segment(high, low);
//             }else if (low.y() == high.y()){
//                 return (low.x < high.x)? Segment(low, high) : Segment(high, low);
//             }else{
//                 return Segment(Cord(0, 0), Cord(0, 0));
//             }
//         }
//     };
// } }
// Implement hash function for map and set data structure
// namespace std{
//     template<>
//     struct hash<Segment>{
//         size_t operator()(const Segment &key) const;
//     };
// }

// std::ostream &operator<<(std::ostream &os, const Segment &c);

#endif  // #define __LINE_H__
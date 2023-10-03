#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>

#include "monitor.h"
#include "cord.h"
#include "units.h"
#include "colours.h"

#include <boost/polygon/polygon.hpp>
#include <assert.h>

namespace gtl = boost::polygon;
using namespace boost::polygon::operators;

int main(int argc, char const *argv[]) {

    // mnt::printCopyRights();

    mCord pt1(10, 20);
    std::priority_queue<mCord> pq;

    pq.emplace(10, 15);
    pq.emplace(12, 13);
    pq.emplace(12, 13);
    pq.emplace(14, 19);
    std::cout << "Check:" << pq.top() << std::endl;


    // for(auto a : pq){
    //     std::cout << a << ", ";
    // }
    // std::cout << std::endl;



    // //using some of the library functions
    // Point pt2(10, 30);
    // assert(gtl::equivalence(pt, pt2));

    // gtl::transformation<int> tr(gtl::axis_transformation::SWAP_XY);
    // gtl::transform(pt, tr);
    // assert(gtl::equivalence(pt, Point(30, 10)));

    // gtl::transformation<int> tr2 = tr.inverse();
    // assert(tr == tr2); //SWAP_XY is its own inverse transform

    // gtl::transform(pt, tr2);
    // assert(gtl::equivalence(pt, pt2)); //the two points are equal again

    // gtl::move(pt, o, 10); //move pt 10 units in y
    // assert(gtl::euclidean_distance(pt, pt2) == 10.0f);

    // gtl::move(pt, o.get_perpendicular(), 10); //move pt 10 units in x
    // assert(gtl::manhattan_distance(pt, pt2) == 20);

    return 0;


}
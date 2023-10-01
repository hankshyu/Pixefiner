#include <iostream>
#include <set>
#include <unordered_set>

#include "monitor.h"
#include "cord.h"
#include "units.h"
#include "colours.h"
int main(int argc, char const *argv[]) {

    mnt::printCopyRights();

    printf("This is about uset cords:");
    std::unordered_set<Cord> us;
    us.insert(Cord(3, 5));
    us.insert(Cord(4, 7));
    us.insert(Cord(11, 2));
    us.insert(Cord(11, 2));

    std::cout << us.count(Cord(4,7));

    return 0;
}
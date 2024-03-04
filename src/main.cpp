#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "boost/polygon/polygon.hpp"
#include "colours.h"
#include "units.h"
#include "cord.h"
#include "line.h"
#include "rectangle.h"
#include "tile.h"
#include "cornerStitching.h"
#include "cSException.h"
#include "rectilinear.h"
#include "doughnutPolygon.h"
#include "doughnutPolygonSet.h"
#include "globalResult.h"
#include "floorplan.h"

#include "eVector.h"

int main(int argc, char const *argv[]) {

	try{

		Cord orig(0, 0);
		Cord c1(1, -1);
		EVector v1 (orig, c1);
		std::cout << v1.calculateL1Magnitude() << std::endl;
		std::cout << v1.calculateL2Magnitude() << std::endl;
		std::cout << v1.calculateDirection() << std::endl;
		EVector ev1(14, 0);
		EVector ev2(11, 0);
		std::cout << vec::calculateAngle(ev1, ev2);
	}catch(CSException c){
		std::cout << "Exception caught -> ";
		std::cout << c.what() << std::endl;
		abort();
	}catch(...){
		std::cout << "Excpetion not caught but aborted!" << std::endl;
		abort();
	}

}
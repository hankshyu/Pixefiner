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
		using namespace boost::polygon::operators;

		std::vector<Cord> cvec = {Cord(10, 20), Cord(10, 40), Cord(20, 40), Cord(20, 30), Cord(30, 30), Cord(30, 20)};


		DoughnutPolygonSet dps;
		DoughnutPolygon dp;
		boost::polygon::set_points(dp, cvec.begin(), cvec.end());

		dps += dp;
		std::vector<Rectangle> frag;
		dps::diceIntoRectangles(dps, frag);
		for(Rectangle const &r : frag){
			std::cout << r << std::endl;
		}

		std::vector<Cord> csurr;
		dp::acquireClockwiseWinding(dp, csurr);
		std::cout << "The windings: " << std::endl;

		for(Cord &c : csurr){
			std::cout << c << std::endl;
		}


		
		
	}catch(CSException c){
		std::cout << "Exception caught -> ";
		std::cout << c.what() << std::endl;
		abort();
	}catch(...){
		std::cout << "Excpetion not caught but aborted!" << std::endl;
		abort();
	}

}
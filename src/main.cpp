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
#include "legalResult.h"

int main(int argc, char const *argv[]) {

	try{
		using namespace boost::polygon::operators;

		// GlobalResult gr;
		// gr.readGlobalResult("inputs/Global_Floorplanning/outputs/case01-output.txt");

		// Floorplan fp(gr, 0.5, 2, 0.8);
		// fp.removePrimitiveOvelaps(true);

		// fp.cs->visualiseCornerStitching("outputs/case01.txt");

		Segment s1 (Cord(4, 5), Cord(6, 3));
		std::cout << s1.low() << std::endl;
		std::cout << s1.high() << std::endl;
		Segment s2 = Segment(Cord(6, 3), Cord(4, 5));
		std::cout << s2.low() << std::endl;
		std::cout << s2.high() << std::endl;
		std::cout << boost::polygon::equivalence(s1, s2) << std::endl;


	}catch(CSException c){
		std::cout << "Exception caught -> ";
		std::cout << c.what() << std::endl;
		abort();
	}catch(...){
		std::cout << "Excpetion not caught but aborted!" << std::endl;
		abort();
	}

}
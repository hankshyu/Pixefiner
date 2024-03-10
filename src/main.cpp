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

		LegalResult lr;
		lr.readLegalResult("./inputs/case01_input.txt");

		Floorplan fp(lr, 0.5, 2, 0.8);
		fp.cs->visualiseCornerStitching("outputs/case01.txt");


		
		
	}catch(CSException c){
		std::cout << "Exception caught -> ";
		std::cout << c.what() << std::endl;
		abort();
	}catch(...){
		std::cout << "Excpetion not caught but aborted!" << std::endl;
		abort();
	}

}
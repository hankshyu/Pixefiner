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
void pdisplay(int a, int b){
	if(a != b) std::cout << "(" << a << " -> " << b;
	else std::cout << a;

	if(a > b) std::cout << GREEN << " -[" << a-b << ", " << double(a-b)*100/a << "%])" << COLORRST;
	else if(b > a) std::cout << RED << " +[" << b-a << ", " << double(b-a)*100/b << "%])" << COLORRST;
}
void pfdisplay(int a, int b){
	if(a != b) std::cout << "(" << a << " -> " << b;
	else std::cout << a;

	if(a > b) std::cout << GREEN << " -[" << a-b << ", " << double(a-b)*100/a << "%])" << COLORRST;
	else if(b > a) std::cout << RED << " +[" << b-a << ", " << double(b-a)*100/b << "%])" << COLORRST;
}
int main(int argc, char const *argv[]) {

	try{
		std::cout << CYAN << "Rectilinear Floorplan Tool" << COLORRST << std::endl << std::endl;
		// Start experiment with

		// using namespace boost::polygon::operators;

		GlobalResult gr;
		gr.readGlobalResult("inputs/Global_Floorplanning/outputs/case01-output.txt");

		Floorplan fp(gr, 0.5, 2, 0.8);

		int overlapCount = 0;
		area_t overlapArea = 0;
		int blockCount = fp.blockTilePayload.size();
		area_t blockArea = 0;
		int totalblockCount = 0;
		area_t totalBlockArea = 0;
		int ov1 = 0;
		int ov2 = 0;
		int ov3 = 0;
		int ov4 = 0;
		area_t ov1a = 0;
		area_t ov2a = 0;
		area_t ov3a = 0;
		area_t ov4a = 0;
		
		for(std::unordered_map<Tile*, Rectilinear*>::const_iterator it = fp.blockTilePayload.begin(); it != fp.blockTilePayload.end(); ++it){
			blockArea += it->first->getArea();
		}
		
		for(std::unordered_map<Tile *, std::vector<Rectilinear *>>::iterator it = fp.overlapTilePayload.begin(); it != fp.overlapTilePayload.end(); ++it){
			int ovSize = it->second.size();
			area_t ovArea = it->first->getArea();
			if(ovSize <= 1){
				ov1++;
				ov1a += ovArea;
			}else if(ovSize == 2){
				ov2++;
				ov2a += ovArea;
			}else if(ovSize == 3){
				ov3++;
				ov3a += ovArea;
			}else{
				ov4++;
				ov4a += ovArea;
			}
			overlapCount++;
			overlapArea += it->first->getArea();
		}

		totalblockCount = overlapCount + blockCount;
		totalBlockArea = overlapArea + blockArea;

		


		fp.removePrimitiveOvelaps(true);
		std::cout << std::endl;


		int poverlapCount = 0;
		area_t poverlapArea = 0;
		int pblockCount = fp.blockTilePayload.size();
		area_t pblockArea = 0;
		int ptotalblockCount = 0;
		area_t ptotalBlockArea = 0;
		
		int pv1, pv2, pv3, pv4;
		area_t pv1a, pv2a, pv3a, pv4a;
		pv1 = pv2 = pv3 = pv4 = 0;
		pv1a = pv2a = pv3a = pv4a = 0;

		for(std::unordered_map<Tile*, Rectilinear*>::const_iterator it = fp.blockTilePayload.begin(); it != fp.blockTilePayload.end(); ++it){
			pblockArea += it->first->getArea();
		}
		
		for(std::unordered_map<Tile *, std::vector<Rectilinear *>>::iterator it = fp.overlapTilePayload.begin(); it != fp.overlapTilePayload.end(); ++it){
			int ovSize = it->second.size();
			area_t ovArea = it->first->getArea();
			if(ovSize <= 1){
				pv1++;
				pv1a += ovArea;
			}else if(ovSize == 2){
				pv2++;
				pv2a += ovArea;
			}else if(ovSize == 3){
				pv3++;
				pv3a += ovArea;
			}else{
				pv4++;
				pv4a += ovArea;
			}
			poverlapCount++;
			poverlapArea += it->first->getArea();
		}

		ptotalblockCount = poverlapCount + pblockCount;
		ptotalBlockArea = poverlapArea + pblockArea;


		std::cout << std::endl;


		std::cout << YELLOW << "Primitive Overlap Removal Report" << COLORRST << std::endl;
		std::cout << CYAN << "Floorplan status" << COLORRST << std::endl;
		std::cout << "Total Tile Count = ";
		pdisplay(totalblockCount, ptotalblockCount);
		std::cout << ", Tile Area = ";
		pfdisplay(totalBlockArea, ptotalBlockArea);
		std::cout << std::endl;

		
		std::cout << "Total tile::BLOCK Count = ";
		pdisplay(blockCount, pblockCount);
		std::cout << ", Block Area = ";
		pfdisplay(blockArea, pblockArea);
		std::cout << std::endl;

		std::cout << "Total tile::OVERLAP Count = ";
		pdisplay(overlapCount, poverlapCount);
		std::cout << ", Overlap Area = ";
		pfdisplay(overlapArea, poverlapArea);
		std::cout << std::endl;
		double beforer = 100*double(overlapArea)/ totalBlockArea;
		double afterr = 100*double(poverlapArea)/ ptotalBlockArea;
		std::cout << "Overall Overlap Ratio = " << beforer << "% -> " << afterr << "% ";
		if(beforer > afterr) std::cout << GREEN << "[-" << beforer - afterr << "%]" << std::endl;
		else if (beforer < afterr) std::cout << GREEN << "+[]" <<  afterr - beforer<< "%]" << std::endl;


		std::cout << std::endl;	
		std::cout << CYAN << "Overlap tiles status" << COLORRST << std::endl;
		std::cout << "Overlap LV1 Count = ";
		pdisplay(ov1, pv1);
		std::cout << ", Area sum = ";
		pfdisplay(ov1a, pv1a);
		std::cout << std::endl;
		
		std::cout << "Overlap LV2 Count = ";
		pdisplay(ov2, pv2);
		std::cout << ", Area sum = ";
		pfdisplay(ov2a, pv2a);
		std::cout << std::endl;

		std::cout << "Overlap LV3 Count = ";
		pdisplay(ov3, pv3);
		std::cout << ", Area sum = ";
		pfdisplay(ov3a, pv3a);
		std::cout << std::endl;
		

		std::cout << "Overlap LV4 Count = ";
		pdisplay(ov4, pv4);
		std::cout << ", Area sum = ";
		pfdisplay(ov4a, pv4a);
		std::cout << std::endl;


		fp.cs->visualiseCornerStitching("outputs/case01.txt");
		std::cout << YELLOW << "Tool Exit Successfully" << COLORRST << std::endl;

	}catch(CSException c){
		std::cout << "Exception caught -> ";
		std::cout << c.what() << std::endl;
		abort();
	}catch(...){
		std::cout << "Excpetion not caught but aborted!" << std::endl;
		abort();
	}

}


// #include "glpk.h"

// int main()
// {
// initialize:
//     glp_prob *lp;
//     lp = glp_create_prob();
//     glp_set_obj_dir(lp, GLP_MAX);
// auxiliary_variables_rows:
//     glp_add_rows(lp, 3);
//     glp_set_row_name(lp, 1, "p");
//     glp_set_row_bnds(lp, 1, GLP_DB, 0.0, 200.0);
//     glp_set_row_name(lp, 2, "q");
//     glp_set_row_bnds(lp, 2, GLP_LO, 10.0, 0.0);
//     glp_set_row_name(lp, 3, "r");
//     glp_set_row_bnds(lp, 3, GLP_DB, 0.0, 275.5);

// variables_columns:
//     glp_add_cols(lp, 2);
//     glp_set_col_name(lp, 1, "x1");
//     glp_set_col_bnds(lp, 1, GLP_LO, 0.0, 0.0);
//     glp_set_col_kind(lp, 1, GLP_IV);
//     glp_set_col_name(lp, 2, "x2");
//     glp_set_col_bnds(lp, 2, GLP_LO, 0.0, 0.0);
//     glp_set_col_kind(lp, 2, GLP_IV);
// to_maximize:
//     glp_set_obj_coef(lp, 1, 10.0);
//     glp_set_obj_coef(lp, 2, 6.0);

// constrant_matrix:
//     int ia[7], ja[7];
//     double ar[7];
//     ia[1] = 1, ja[1] = 1, ar[1] = 1;
//     ia[2] = 1, ja[2] = 2, ar[2] = 1; // p = x1 + x2
//     ia[3] = 2, ja[3] = 1, ar[3] = 1;
//     ia[4] = 2, ja[4] = 2, ar[4] = 2; // q = x1 + 2x2
//     ia[5] = 3, ja[5] = 1, ar[5] = 3;
//     ia[6] = 3, ja[6] = 2, ar[6] = 1; // r = 3x1 + x2
//     glp_load_matrix(lp, 6, ia, ja, ar);

// calculate:
//     glp_simplex(lp, NULL);
//     glp_intopt(lp, NULL);

// output:
//     double z, x1, x2;
//     z = glp_get_obj_val(lp);
//     x1 = glp_mip_col_val(lp, 1);
//     x2 = glp_mip_col_val(lp, 2);
//     printf("z = %lf, x1 = %lf, x2 = %lf\n", z, x1, x2);

// cleanup:
//     glp_delete_prob(lp);
//     return 0;
// }
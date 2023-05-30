// Program which will take in conditions, and return
// the solution to the pde its trying to solve

// 20 May 2023




#include <cmath>
#include <vector>

#include "pde_solver.hpp"
#include "../memory/domain.hpp"


using namespace LBSIM;


pde_solver::PDE_Solver(memory::Domain potDomain,
		       int xRange,
		       int yRange){

  xTotalRange = xRange;
  yTotalRange = yRange;
}



memory::Domain pde_solver::pde_solver(){

  
  // Delta being a measurement of how close the
  // solver is getting to converging to a solution
  double delta = 0;
  
  while(delta > 0.05){
    
    for(int y=0; y<yRange; y++){
      for(int x=0; x<xRange; x++){
	
      
      }
    }
    
  }
}

double pde_solver::potentialTop(int xSpot,
				int ySpot){
  std::cout << myDomain.at(ySpot*yTotalRange+xSpot).getPotential() << " \n";

}

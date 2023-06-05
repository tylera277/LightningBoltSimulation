// Program which will take in conditions, and return
// the solution to the pde its trying to solve

// 20 May 2023




#include <cmath>
#include <vector>
#include <iostream>
#include <exception>

#include "pde_solver.hpp"
#include "memory/cell.hpp"
#include "../memory/domain.hpp"


using namespace LBSIM;


// Constructor
solver::PDE_Solver::PDE_Solver(memory::Domain domain,
			       memory::Domain bc_domain,
			       int xRange,
			       int yRange):
  _bcPotDomain(bc_domain),
  _potDomain(domain),
  _xTotalRange(xRange),
  _yTotalRange(yRange){

  // implementation detail of constructor section if needed
  
}



void solver::PDE_Solver::pde_solver(){

  
  // Delta being a measurement of how close the
  // solver is getting to converging to a solution,
  // (the change in potential from one iteration to the next)
  double delta = 1;
  double potentialCenter, newPotentialCenter;
  double potentialTop, potentialBot, potentialLeft, potentialRight;
  
  while(delta > 0.0005){
    
    //std::cout << "DELTA: " << delta << "\n";

    delta = 0;
    for(int y=1; y<(_yTotalRange+1); y++){
      for(int x=1; x<(_xTotalRange+1); x++){

	if((this->potentialOfBCCell(x,y)) != 10)
	  {
	    continue;
	  }
	else
	  {

	    // Getting the potential of the four cells around the center one,
	    // later used in calculations
	    try
	      {
		
		potentialCenter = this-> potentialOfCell (x, y);
		
		potentialTop = this-> potentialOfCell   ( x , y-1 );
		potentialBot = this-> potentialOfCell   ( x , y+1 );
		potentialLeft = this-> potentialOfCell  ( x-1, y);
		potentialRight = this-> potentialOfCell ( x+1, y);
		
	      }
	    catch(const std::exception& e)
	      {
		std::cout << "Exception occurred: " << e.what() << std::endl;
		
		try {
		  std::rethrow_exception(std::current_exception());
		}
		catch (const std::exception& innerException) {
		  std::cout << "Exception thrown at: " << __FILE__ << ":" << __LINE__ << std::endl;
		  std::terminate();
		}
	      }

	
	    std::vector<double> arrayPotential = {potentialTop, potentialBot,
	      potentialLeft, potentialRight};
	    
				 

	    
	    
	    newPotentialCenter = this-> calculateNewPotentialOfCenter(arrayPotential);

	    
	    this->setPotentialOfCell( x, y, newPotentialCenter);
	    delta += std::abs(potentialCenter - newPotentialCenter);
	    
	  }
	
      }
    }

  }

  delta = delta / (_xTotalRange * _yTotalRange);
}

double solver::PDE_Solver::potentialOfCell(int xSpot, int ySpot)
{

  double potentialOfCell = _potDomain.getPotentialOfCell( xSpot, ySpot);

  return potentialOfCell;
}


void solver::PDE_Solver::setPotentialOfCell(int xSpot, int ySpot, double newPotential)
{
  _potDomain.setPotentialOfCell(xSpot, ySpot, newPotential);

}



double solver::PDE_Solver::potentialOfBCCell(int xSpot, int ySpot)
{
  double potentialOfBCCell = _bcPotDomain.getPotentialOfCell(xSpot, ySpot);

  return potentialOfBCCell;

}

  



double solver::PDE_Solver::calculateNewPotentialOfCenter(std::vector<double> potentialArray)
{

  double potentialCenter;
  double potentialTop, potentialBot, potentialLeft, potentialRight;

  double calculatedPotentialCenter;
  
  potentialTop = potentialArray.at(0);
  potentialBot = potentialArray.at(1);
  potentialLeft = potentialArray.at(2);
  potentialRight = potentialArray.at(3);

  calculatedPotentialCenter = (1.0/4.0) * (potentialLeft + potentialRight \
					   + potentialBot + potentialTop);

  return calculatedPotentialCenter;
  
}
							 

void solver::PDE_Solver::printAllPotentialValues()
{
  double potential;
  
  for( int y=0; y<(_yTotalRange+1); y++){
    for( int x=0; x<(_xTotalRange+1); x++){
      
      potential = this->potentialOfCell(x,y);
      std::cout << potential << " : ";
    }
    std::cout << "\n";
  }
  

}

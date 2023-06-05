


#ifndef PDE_SOLVER_H
#define PDE_SOLVER_H


#include <vector>


#include "../memory/domain.hpp"
#include "../memory/cell.hpp"


namespace LBSIM{

  namespace solver{


    class PDE_Solver
    {
    private:
      int _xTotalRange, _yTotalRange;
      memory::Domain _potDomain, _bcPotDomain;


    public:

      PDE_Solver(memory::Domain domain, memory::Domain bc_domain,
		 int xRange, int yRange);
	
      
      void pde_solver();

      double potentialOfCell( int xSpot, int ySpot );
      
      double potentialOfBCCell( int xSpot, int ySpot);

      double calculateNewPotentialOfCenter(std::vector<double> potentialArray);

      void setPotentialOfCell(int xSpot, int ySpot, double newPotential);

      void printAllPotentialValues();
    
    };

  }// namespace solver
}//  namespace LBSIM

#endif
			       

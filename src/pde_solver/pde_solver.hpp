
// PDE_Solver:: Class housing main functions which handle
//   the details of actually solving and getting info needed
//   to achieve to that end.



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

      // Constructor
      PDE_Solver(memory::Domain domain, memory::Domain bc_domain,
		 int xRange, int yRange);
      
      /*
      Main function which orchestrates all the sub functions
      */
      void pde_solver();

      
      /*
      Retrieves the potential value at a specified cell location
      */
      double potentialOfCell( int xSpot, int ySpot );

      
      /*
       Retrieves the potential value at a *boundary condition* cell,
      used for telling if calculation needs to be done at the cell
      */
      double potentialOfBCCell( int xSpot, int ySpot);

      
      /*
      Takes as input the surrounding cells potential values,
       and performs math to calculate the new value in the center of them
       (essentially an averaging of them in the simplest of cases)
      */
      double calculateNewPotentialOfCenter(std::vector<double> potentialArray);

      
      /*
      Setting the potential of a cell at a specified cell location with
       the new potential value specified as well in the function input
      */ 
      void setPotentialOfCell(int xSpot, int ySpot, double newPotential);


      void setPotentialOfBCCell(int xSpot, int ySpot, double newPotential);




      /*
	Retrieving from the domain, the cells which are adjacent to a negative
	 charge.
      */
      std::vector< memory::Cell > cellAdjacentToNegativeCharges();


      
      void pickRandomCell(std::vector<memory::Cell> adjacentCells,
				  double eta);


      void resetPotentialCells();
      

      /*
	Used for printing out the array of potential values out to the terminal.
      */
      void printAllPotentialValuesTerminal();


      /*
	Used for printing potential values out to a csv file using a name
	the user specifies, as well as if the simulation just started or has
	been running
      */
      void printAllPotentialValuesCSV(double currentTimeInterval, std::string file_name);


      
      
    
    };

  }// namespace solver
}//  namespace LBSIM

#endif
			       

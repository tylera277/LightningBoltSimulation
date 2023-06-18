
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
      
      

     /**
      * @brief Main function which orchestrates all the sub functions in solving the pde
      * 
      * Function which is the main solver of the pde
      * 
      */
      void pde_solver();

      
      /**
      * @brief Retrieves the calculated potential value at a spot
      * @param xSpot the x location of the desired spot
      * @param ySpot the y location   "       "
      * @return the potential of the specified spot
      *
      */
      double potentialOfCell( int xSpot, int ySpot );

      

     /**
      * @brief Retrieves the potential at a *boundary condition* cell
      * @param xSpot the x location of the desired spot
      * @param ySpot the y location   "       "
      * @return the potential in the boundary condition array
      *
      * -Used for telling if calculation needs to be done at the cell
      * -If its a boundary condition, dont calculate a potential there b/c
      * its already been set.
      */
      double potentialOfBCCell( int xSpot, int ySpot);

      
      
     /**
      * @brief Calculate the new potential of a cell
      * @param potentialArray An array comprised of the four surrounding cells
      * @return The calculated new potential
      *
      * - Calculates the new potential value given the four surrounding ones
      * and returns it to the call location.
      * - Mathematically taking the average of all four
      */ 
      double calculateNewPotentialOfCenter(std::vector<double> potentialArray);

      
      /*
      Setting the potential of a cell at a specified cell location with
       the new potential value specified as well in the function input
      */ 

     /**
      * @brief Setting the potential of a cell at a location
      * @param xSpot the x location of the desired spot
      * @param ySpot the y location   "       "
      * @param newPotential the new potential value you want to insert
      *
      * Inserts a newly calculated potential value in the grid
      */ 
      void setPotentialOfCell(int xSpot, int ySpot, double newPotential);



      /**
      * @brief Setting the potential of a boundary condition cell at a location
      * @param xSpot the x location of the desired spot
      * @param ySpot the y location   "       "
      * @param newPotential the new potential value you want to insert into
      * the boundary condition grid
      *
      * Inserts a newly calculated potential value in the BC grid
      */ 

      void setPotentialOfBCCell(int xSpot, int ySpot, double newPotential);




      /*
	Retrieving from the domain, the cells which are adjacent to a negative
	 charge.
      */
      std::vector< memory::Cell > cellAdjacentToNegativeCharges();


      
      void pickRandomCell(std::vector<memory::Cell> adjacentCells,
				  double eta);


      bool checkIfInListAlready(std::vector<memory::Cell> listOfCells,
				int xPositionInQuestion,
				int yPositionInQuestion);

      
      

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
			       

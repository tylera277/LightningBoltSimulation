


#include <vector>
#include <string>
#include <iostream>


#include "memory/domain.hpp"
#include "memory/cell.hpp"
#include "pde_solver/pde_solver.hpp"



using namespace LBSIM;


int main(){
  
  /*
   1.) Set boundary conditions (BC's) and define the grid size, as well
    as other initial conditions (IC's)

    ->either dot in circle or traditional bolt model
  */
  std::string initialBoardLayout = "traditional_lightning_model";
  

  // Initialize a domain where everything will be stored in

  int xRange = 100;
  int yRange = 100;
  
  memory::Domain myDomain(xRange, yRange, -1);
  memory::Domain bcDomain(xRange, yRange, 10);

  try
    {
      bcDomain.initializeDomainToUsersChoice(initialBoardLayout);
      myDomain.initializeDomainToUsersChoice(initialBoardLayout);
    }
  catch( std::exception& e)
    {
       std::cout << "Exception occurred: " << e.what() << std::endl;
       
       try
	 {
	 std::rethrow_exception(std::current_exception());
	 }
       catch (const std::exception& innerException)
	 {
	   std::cout << "Exception thrown at: " << __FILE__ << ":" << __LINE__ << std::endl;
	   std::terminate();
	 }
       
    }

       
    
  //bcDomain.printPotentialValues();


  // Main loop
  int tEnd = 10;
  int dt = 1;
  double eta=1.0;

  // File where I will be outputting the values to, in order to be
  // later plotted using a python script
  std::string output_file = "../src/outputData/10jun2023_data.csv";


  std::vector<memory::Cell> adjacentCells;
  
  solver::PDE_Solver solverInstance(myDomain, bcDomain, xRange, yRange);

  for(int t=0;t<tEnd; t += dt)
    {

      solverInstance.pde_solver();

      //solverInstance.printAllPotentialValuesTerminal();


      adjacentCells = solverInstance.cellAdjacentToNegativeCharges();

      solverInstance.pickRandomCell(adjacentCells, eta);

      if(t != (tEnd-1))
	{
	  solverInstance.resetPotentialCells();
	}
     
    }
  

  solverInstance.printAllPotentialValuesCSV(0, output_file);

  

  /*
    4.) Randomly choose one of these cells as a growth site,
    with a probability based off of the eqn. in my notes
   */


  /*
    5.) The chosen cell is set to phi=0 and is treated as part of the 
    B.C.'s in the next iterations
   */
  





}

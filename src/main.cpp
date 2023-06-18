// Program which has the goal of simulating a lightning bolt


#include <vector>
#include <string>
#include <iostream>


#include "simulation_defines.hpp"
#include "memory/domain.hpp"
#include "memory/cell.hpp"
#include "pde_solver/pde_solver.hpp"



using namespace LBSIM;


int main(){
  
  
  // Initializing the domains that will be used in the simulation
  //  - myDomain : storing calculated potential values
  //  - bcDomain : storing the boundary conditions 
  //             (the 10 value for BC is important for my program atm)                  
  memory::Domain myDomain(simParams::xTotalCells, simParams::yTotalCells, 0);
  memory::Domain bcDomain(simParams::xTotalCells, simParams::yTotalCells, 10);

  try
    {
      bcDomain.initializeDomainToUsersChoice(simParams::initialBoardLayout);
      myDomain.initializeDomainToUsersChoice(simParams::initialBoardLayout);
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


  std::vector<memory::Cell> adjacentCells;
  
  solver::PDE_Solver solverInstance(myDomain, bcDomain, simParams::xTotalCells, simParams::yTotalCells);


  for(int t = simParams::simulationStartingPoint; t < simParams::simulationLength; 
  t += simParams::simulationIncrement)
    {

      solverInstance.pde_solver();

      adjacentCells = solverInstance.cellAdjacentToNegativeCharges();

      solverInstance.pickRandomCell(adjacentCells, simParams::eta);

      if(t != (simParams::simulationLength-1))
      {
      solverInstance.resetPotentialCells();
      }
     
    }
  

  solverInstance.printAllPotentialValuesCSV(0, simParams::outputFile);


  
}

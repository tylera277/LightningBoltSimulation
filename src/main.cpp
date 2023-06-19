// Program which has the goal of simulating a lightning bolt


#include <vector>
#include <string>
#include <iostream>
#include <chrono>

#include "simulation_defines.hpp"
#include "memory/domain.hpp"
#include "memory/cell.hpp"
#include "pde_solver/pde_solver.hpp"



using namespace LBSIM;


int main(){
  
  
  auto startTime = std::chrono::steady_clock::now();

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

       
    

  // Main loop

  std::vector<memory::Cell> adjacentCells;
  
  solver::PDE_Solver solverInstance(myDomain, bcDomain, simParams::xTotalCells, simParams::yTotalCells);

  auto checkPoint1 = std::chrono::steady_clock::now();

  for(int t = simParams::simulationStartingPoint; t < simParams::simulationLength; 
      t += simParams::simulationIncrement)
    {

      auto inLoopTime1 = std::chrono::steady_clock::now();


      solverInstance.pde_solver();

      
      auto inLoopTime2 = std::chrono::steady_clock::now();


      adjacentCells = solverInstance.cellAdjacentToNegativeCharges();

      solverInstance.pickRandomCell(adjacentCells, simParams::eta);
     

      //if( solverInstance.detectIfFinished() == true)
      //{
       // std::cout << "Simulation has finished!\n";
       // break;
      //}


      auto inLoopTime3 = std::chrono::steady_clock::now();

      std::cout << "Section 1: " << std::chrono::duration_cast<std::chrono::milliseconds>(inLoopTime2 - inLoopTime1).count() << "ms" << std::endl;
      std::cout << "Section 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(inLoopTime3 - inLoopTime2).count() << "ms" << std::endl;
    }
  
  // Prints final values out to a specified csv file.
  solverInstance.printAllPotentialValuesCSV(0, simParams::outputFile);


  
}

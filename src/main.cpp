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
  
  solver::PDE_Solver solverInstance(myDomain, bcDomain, simParams::xTotalCells, simParams::yTotalCells,
  simParams::outputPotentialFile, simParams::outputBCFile);

  auto checkPoint1 = std::chrono::steady_clock::now();

  

  for(int t = simParams::simulationStartingPoint; t < simParams::simulationLength;
   t += simParams::simulationIncrement)
    {
      std::cout << "TIME: " << t << "\n";  
      if(t==int((simParams::simulationLength)/4))
      { 
        //std::cout <<"HAPPENED!\n";
        solverInstance.printAllPotentialValuesCSV(0);
        solverInstance.printAllBoundaryConditionValuesCSV(0);

      }
      if(t==int((simParams::simulationLength)/2))
      {
        solverInstance.printAllPotentialValuesCSV(1);
        solverInstance.printAllBoundaryConditionValuesCSV(1);
      }
      if(t==int((3*(simParams::simulationLength))/4))
      {
        solverInstance.printAllPotentialValuesCSV(2);
        solverInstance.printAllBoundaryConditionValuesCSV(2);
      }
      


      auto inLoopTime1 = std::chrono::steady_clock::now();

      solverInstance.pde_solver();

      
      auto inLoopTime2 = std::chrono::steady_clock::now();


      adjacentCells = solverInstance.cellAdjacentToNegativeCharges();

      solverInstance.pickRandomCell(adjacentCells, simParams::eta);
     

      // This is printing out the total potential thats spread
      // out in all of the cells; I think it should be relatively constant
      // throughout the entire simulation
      //solverInstance.printAllPotentialValuesTerminal();

      /* 
      if( solverInstance.detectIfFinished() )
      {
        std::cout << "Simulation has finished!\n";
        break;
      }
      */

      auto inLoopTime3 = std::chrono::steady_clock::now();

      //std::cout << "Section 1: " << std::chrono::duration_cast<std::chrono::milliseconds>(inLoopTime2 - inLoopTime1).count() << "ms" << std::endl;
      //std::cout << "Section 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(inLoopTime3 - inLoopTime2).count() << "ms" << std::endl;
    }
  
  // Prints final values out to a specified csv file.
  solverInstance.printAllPotentialValuesCSV(3);
  solverInstance.printAllBoundaryConditionValuesCSV(3);

  
}

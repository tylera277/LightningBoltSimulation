// Program which has the goal of simulating a lightning bolt


#include <vector>
#include <string>
#include <iostream>

#include "simulation_defines.hpp"
#include "memory/domain.hpp"
#include "memory/cell.hpp"
#include "pde_solver/pde_solver.hpp"

#include "../spdlog/spdlog.h"
#include "../spdlog/sinks/basic_file_sink.h"

using namespace LBSIM;


int main(){

  auto logger = spdlog::basic_logger_mt("basic_logger", simParams::outputErrorFile);
  spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

  logger->info("Program is starting...");
  

  logger->info("Initializing domains...");
  // Initializing the domains that will be used in the simulation
  //  - myDomain : storing calculated potential values
  //  - bcDomain : storing the boundary conditions 
  //             (the 10 value for BC is important for my program at the moment)                  
  memory::Domain myDomain(simParams::xTotalCells, simParams::yTotalCells, 0);
  memory::Domain bcDomain(simParams::xTotalCells, simParams::yTotalCells, 10);

  //bcDomain.initializeDomainToUsersChoice(simParams::initialBoardLayout);
  //myDomain.initializeDomainToUsersChoice(simParams::initialBoardLayout);

  try
    {
      bcDomain.initializeDomainToUsersChoice(simParams::initialBoardLayout);
      myDomain.initializeDomainToUsersChoice(simParams::initialBoardLayout);
    }
  catch( std::exception& e)
    {
      logger->error("[{}:{}] {}",__FILE__, __LINE__, "ERROR IN INITIALIZING DOMAINS!" );
      std::terminate();
       
    }

       
    

  // Main loop

  std::vector<memory::Cell> adjacentCells;
  
  solver::PDE_Solver solverInstance(myDomain, bcDomain, simParams::xTotalCells, simParams::yTotalCells,
  simParams::outputPotentialFile, simParams::outputBCFile);

  
  int timeChunk = simParams::simulationLength;

  logger->info("Starting potential calculation loop...");
  
  for(int t = simParams::simulationStartingPoint; t < simParams::simulationLength;
   t += simParams::simulationIncrement)
    {
      

      if(t==(timeChunk/4))
      { 
        solverInstance.printAllPotentialValuesCSV(0);
        solverInstance.printAllBoundaryConditionValuesCSV(0);

      }
      if(t==(timeChunk)/2)
      {
        solverInstance.printAllPotentialValuesCSV(1);
        solverInstance.printAllBoundaryConditionValuesCSV(1);
      }
      if(t == (timeChunk/4))
      {
        solverInstance.printAllPotentialValuesCSV(2);
        solverInstance.printAllBoundaryConditionValuesCSV(2);
      }
      

      solverInstance.pde_solver();

      
      

      adjacentCells = solverInstance.cellAdjacentToNegativeCharges();

      solverInstance.pickRandomCell(adjacentCells, simParams::eta);
     
    }
  
  logger->info("Printing final results of simulation...");
  // Prints final values out to a specified csv file.
  solverInstance.printAllPotentialValuesCSV(3);
  solverInstance.printAllBoundaryConditionValuesCSV(3);


  logger->info("Program completed execution.");
  logger->info("------------");
  spdlog::drop_all();

}

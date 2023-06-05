


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
  std::string initialBoardLayout = "dot_in_circle";
  

  // Initialize a domain where everything will be stored in

  int xRange = 10;
  int yRange = 10;
  
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

       
    
  myDomain.printPotentialValues();


  // Main loop
  int tEnd = 2;
  int dt = 1;
  
  for(int t=0;t<tEnd; t += dt){


    solver::PDE_Solver solverInstance(myDomain, bcDomain, xRange, yRange);

    solverInstance.pde_solver();

    solverInstance.printAllPotentialValues();

    std::cout << "-------------" << "\n";
      
    
  }
  /*
    2.) Input those B.C.'s into a function
    which solves the Laplace eqn. over the grid of cells
    specified
   */


  /*
    3.) Get a list of all of the grid cells that are adjacent
    to a negative charge (phi=0)
   */


  /*
    4.) Randomly choose one of these cells as a growth site,
    with a probability based off of the eqn. in my notes
   */


  /*
    5.) The chosen cell is set to phi=0 and is treated as part of the 
    B.C.'s in the next iterations
   */
  





}

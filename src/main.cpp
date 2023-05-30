


#include <vector>
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
  //intialBoardLayout = "dot_in_circle";
  

  // Initialize a domain where everything will be stored in

  int xRange = 10;
  int yRange = 10;
  
  memory::Domain myDomain(xRange, yRange);

  myDomain.printPotentialValues();
 


  // Main loop
  int tEnd = 1000;
  int dt = 1;
  
  for(int t=0;t<tEnd; t += dt){
  
    myDomain = pde_solver::pde_solver(myDomain,
				      xRange,
				      yRange);
    
    
    
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

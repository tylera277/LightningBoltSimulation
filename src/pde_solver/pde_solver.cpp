// Program which will take in conditions, and return
// the solution to the pde its trying to solve

// 20 May 2023




#include <cmath>
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include <random>

#include "pde_solver.hpp"
#include "../memory/cell.hpp"
#include "../memory/domain.hpp"
#include "../simulation_defines.hpp"

#include "../../spdlog/spdlog.h"
#include "../../spdlog/sinks/basic_file_sink.h"

using namespace LBSIM;

auto logger = spdlog::basic_logger_mt("pde_solver_logger", simParams::outputErrorFile);

// Constructor
solver::PDE_Solver::PDE_Solver(memory::Domain domain,
			       memory::Domain bc_domain,
			       int xRange,
			       int yRange,
             std::string outputPotFile,
             std::string outputBCFile):
  _bcPotDomain(bc_domain),
  _potDomain(domain),
  _xTotalRange(xRange),
  _yTotalRange(yRange),
  _outputPotFile(outputPotFile),
  _outputBCFile(outputBCFile){

  // implementation detail of constructor section if needed
  
}




void solver::PDE_Solver::pde_solver(){

  
  // Delta being a measurement of how close the
  // solver is getting to converging to a solution,
  // (the change in potential from one iteration to the next)
  double delta = 1;
  double potentialCenter, newPotentialCenter;
  double potentialTop, potentialBot, potentialLeft, potentialRight;

  while(delta > simParams::ceaseCondition){
    delta = 0;
    
    for(int y=1; y<(_yTotalRange+1); y++){
      for(int x=1; x<(_xTotalRange+1); x++){

	if((this->potentialOfBCCell(x,y)) != 10)
	  {
	    continue;
	  }
	else
	  {

	    // Getting the potential of the four cells around the center one,
	    // later used in calculations
	    try
	      {
		
		    potentialCenter = this-> potentialOfCell (x, y);
		    potentialTop = this-> potentialOfCell   ( x , y-1 );
		    potentialBot = this-> potentialOfCell   ( x , y+1 );
		    potentialLeft = this-> potentialOfCell  ( x-1, y);
		    potentialRight = this-> potentialOfCell ( x+1, y);
		
	      }
	    catch(const std::exception& e)
	      {
          logger->error("[{}:{}] {}",__FILE__, __LINE__, "ERROR IN CALCULATING POTENTIAL" );
          break;
        }

	
	    std::vector<double> arrayPotential = {potentialTop, potentialBot,
	      potentialLeft, potentialRight};
   
	    
	    newPotentialCenter = this-> calculateNewPotentialOfCenter(arrayPotential);

	    
	    this->setPotentialOfCell( x, y, newPotentialCenter);
	    delta += std::abs(potentialCenter - newPotentialCenter);
	    
	      
	  }
	
      }
    }
    //std::cout << "pre DEL:" << delta << "\n";
    delta /= ( (_xTotalRange+2) * (_yTotalRange+2) );
    //std::cout << "postDEL:" << delta << "\n";
    //std::cout << "------------" << "\n";
  }

}




double solver::PDE_Solver::potentialOfCell(int xSpot, int ySpot)
{

  double potentialOfCell = _potDomain.getPotentialOfCell( xSpot, ySpot);

  return potentialOfCell;
}

double solver::PDE_Solver::potentialOfBCCell(int xSpot, int ySpot)
{
  double potentialOfBCCell = _bcPotDomain.getPotentialOfCell(xSpot, ySpot);

  return potentialOfBCCell;

}



void solver::PDE_Solver::setPotentialOfCell(int xSpot, int ySpot, double newPotential)
{
  _potDomain.setPotentialOfCell(xSpot, ySpot, newPotential);

}

void solver::PDE_Solver::setPotentialOfBCCell(int xSpot, int ySpot, double newPotential)
{
  _bcPotDomain.setPotentialOfCell(xSpot, ySpot, newPotential);

}

  



double solver::PDE_Solver::calculateNewPotentialOfCenter(std::vector<double> potentialArray)
{

  double potentialCenter;
  double potentialTop, potentialBot, potentialLeft, potentialRight;

  double calculatedPotentialCenter;
  
  potentialTop = potentialArray.at(0);
  potentialBot = potentialArray.at(1);
  potentialLeft = potentialArray.at(2);
  potentialRight = potentialArray.at(3);

  calculatedPotentialCenter = (1.0/4.0) * (potentialLeft + potentialRight \
					   + potentialBot + potentialTop);

  return calculatedPotentialCenter;
  
}



std::vector< memory::Cell > solver::PDE_Solver::cellAdjacentToNegativeCharges()
{
  double potential, checkPotential, calculatedPotential;
  std::vector< memory::Cell > adjacentCells;
  
  for( int y=2; y<(_yTotalRange); y++)
    {
    for( int x=2; x<(_xTotalRange); x++)
      {
	     potential = this->potentialOfBCCell(x,y);

	    if(potential==0)
	      {
	    
	    for(int i=-1 ; i<2 ; i++)
	      {
		    for(int j=-1 ; j<2; j++)
		      {
		    
		    if(i==0 && j==0)
		      {
			      continue;
		      }
		    
		    checkPotential = this->potentialOfBCCell( x+i , y+j );
		    calculatedPotential = this->potentialOfCell( x+i , y+j );
		    if(checkPotential==0)
		      {
		        continue;
		      }
		    if( this->checkIfInListAlready(adjacentCells, x+i, y+j ) )
		      {
		        continue;
		      }

		    memory::Cell c( x+i, y+j, std::abs(calculatedPotential));
		    adjacentCells.push_back(c);
		    
		    }

	      }
	    
	      
	    
	  }
     
      }
    }
  
  return adjacentCells;
}



bool solver::PDE_Solver::checkIfInListAlready(std::vector<memory::Cell> listOfCells,
					      int xPosition, int yPosition)
{
  int xInList, yInList;
  for(int i=0; i < listOfCells.size(); i++)
    {
      
      xInList = ( listOfCells.at(i) ).getX();
      yInList = ( listOfCells.at(i) ).getY();


      if((xInList == xPosition) && (yInList == yPosition))
	    {
	      return true;
	    }

    }
  return false;

  
}




void solver::PDE_Solver::pickRandomCell(std::vector< memory::Cell > adjacentCells, double eta)
{

  int lengthOfAdjacentCells = adjacentCells.size();
  double randomInteger;
  double totalPotential = 0;
  srand ( time(NULL) );
  
  std::random_shuffle(adjacentCells.begin(), adjacentCells.end());
  
    for( int num=0; num<lengthOfAdjacentCells; num++ )
      {
	      totalPotential += (std::pow(std::abs((adjacentCells.at(num)).getPotential()), eta));
	    
      }


      //std::cout<<"totalPotentialAdjacentCells:" << totalPotential<< "\n";

    // A real skunkworks attempt at developing something to select numbers
    // based off of a certain probability distribution
    randomInteger = std::rand() % 100;
    double prevNum = 0;


    
    for( int num=0; num<lengthOfAdjacentCells; num++ )
      {
	      double currentNum = (std::pow((adjacentCells.at(num)).getPotential(),eta) \
        /totalPotential)*100;
	
	      //std::cout<<"CURRNUM:" << currentNum << "\n";
        

	      if(( randomInteger >= prevNum ) && (randomInteger < (prevNum+currentNum) ))
	        {

	   
	          this->setPotentialOfBCCell(adjacentCells.at(num).getX(),
				    adjacentCells.at(num).getY(), 0);

            
            this->setPotentialOfCell(adjacentCells.at(num).getX(),
				    adjacentCells.at(num).getY(), 0);



            //std::cout << "X_pot: " << adjacentCells.at(num).getX() << ", Y_pot: " << \
            //adjacentCells.at(num).getY() << ", Pot: " << \
            //this->potentialOfCell(adjacentCells.at(num).getX(), adjacentCells.at(num).getY())<<"\n";

	          //std::cout << "SUSPECT-> XPOS:" << adjacentCells.at(num).getX() << "; YPOS: " <<
	          //(adjacentCells.at(num)).getY() << "\n";
	          break;
	        }
	
	      prevNum += currentNum;
	
      }

    
}


void solver::PDE_Solver::resetPotentialCells()
{
  for(int y=1; y<(_yTotalRange+1); y++)
    {
      for(int x=1; x<(_xTotalRange+1); x++)
	{
	  double potBCCell = this->potentialOfBCCell(x,y);
	  
	  if(potBCCell != 10)
	    {
	      this->setPotentialOfCell(x,y,potBCCell);
	    }
	  else
	    {
        if(x==(_xTotalRange+1))
        {
          this->setPotentialOfCell(x,y,1);
        }
	      else
        {
          this->setPotentialOfCell(x,y,0);
        }
	    }
	      
	}
    }
  

}


bool solver::PDE_Solver::detectIfFinished()
{
  for(int i=1 ; i<(_xTotalRange+1) ; i++)
  {
    double bc_potential = this->potentialOfBCCell(i, _yTotalRange);

    if(bc_potential != 10)
    { 
      return true;
    }
  }
  return false;

}















void solver::PDE_Solver::printAllPotentialValuesTerminal()
{
  double potential;
  double totalPotential = 0;

  for( int y=1; y<(_yTotalRange+1); y++)
    {
    for( int x=1; x<(_xTotalRange+1); x++)
      {
      
	    potential = this->potentialOfCell(x,y);
      totalPotential += potential;
    }
    
  }
  std::cout << "TotalPotential: " << totalPotential << " \n ";


}


void solver::PDE_Solver::printAllPotentialValuesCSV(double currentTime)
{

  std::ofstream angles;

  // Using this check to see if this is the start of the simulation,
  // if it is, overwrite the data currently in the csv file
  if ( currentTime == 0 )
    {
      angles.open(_outputPotFile);
    }
  else if(currentTime != 0)
    {
      angles.open(_outputPotFile, std::ios::app);
    }
  double potential;

  for( int y=1; y<(_yTotalRange+1); y++)
    {
    for( int x=1; x<(_xTotalRange+1); x++)
      {
      
      potential = this->potentialOfCell( x , y );
      angles << potential << " , ";
      }
    angles << "\n";
    }
  angles << "\n";
  
      
  
  angles.close();
  

}


void solver::PDE_Solver::printAllBoundaryConditionValuesCSV(double currentTime)
{

  std::ofstream angles;

  // Using this check to see if this is the start of the simulation,
  // if it is, overwrite the data currently in the csv file
  if ( currentTime == 0 )
    {
      angles.open(_outputBCFile);
    }
  else if(currentTime != 0)
    {
      angles.open(_outputBCFile, std::ios::app);
    }
  double potential;

  for( int y=1; y<(_yTotalRange+1); y++)
    {
    for( int x=1; x<(_xTotalRange+1); x++)
      {
      
      potential = this->potentialOfBCCell( x , y );
      angles << potential << " , ";
      }
    angles << "\n";
    }
  angles << "\n";
  
      
  
  angles.close();
  

}



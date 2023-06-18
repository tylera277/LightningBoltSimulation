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

#include "pde_solver.hpp"
#include "../memory/cell.hpp"
#include "../memory/domain.hpp"


using namespace LBSIM;


// Constructor
solver::PDE_Solver::PDE_Solver(memory::Domain domain,
			       memory::Domain bc_domain,
			       int xRange,
			       int yRange):
  _bcPotDomain(bc_domain),
  _potDomain(domain),
  _xTotalRange(xRange),
  _yTotalRange(yRange){

  // implementation detail of constructor section if needed
  
}




void solver::PDE_Solver::pde_solver(){

  
  // Delta being a measurement of how close the
  // solver is getting to converging to a solution,
  // (the change in potential from one iteration to the next)
  double delta = 1;
  double potentialCenter, newPotentialCenter;
  double potentialTop, potentialBot, potentialLeft, potentialRight;
  
  while(delta > 0.005){
 
    //std::cout << "DELTA: " << delta << "\n";
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
		std::cout << "Exception occurred: " << e.what() << std::endl;
		
		try {
		  std::rethrow_exception(std::current_exception());
		}
		catch (const std::exception& innerException) {
		  std::cout << "Exception thrown at: " << __FILE__ << ":" << __LINE__ << std::endl;
		  std::terminate();
		}
	      }

	
	    std::vector<double> arrayPotential = {potentialTop, potentialBot,
	      potentialLeft, potentialRight};
   
	    
	    newPotentialCenter = this-> calculateNewPotentialOfCenter(arrayPotential);

	    
	    this->setPotentialOfCell( x, y, newPotentialCenter);
	    delta += std::abs(potentialCenter - newPotentialCenter);
	    //std::cout << "DEL:" <<std::abs(potentialCenter - newPotentialCenter) << "\n";
	      
	  }
	
      }
    }
    delta /= ( (_xTotalRange+2) * (_yTotalRange+2) );


  }

}




double solver::PDE_Solver::potentialOfCell(int xSpot, int ySpot)
{

  double potentialOfCell = _potDomain.getPotentialOfCell( xSpot, ySpot);

  return potentialOfCell;
}



void solver::PDE_Solver::setPotentialOfCell(int xSpot, int ySpot, double newPotential)
{
  _potDomain.setPotentialOfCell(xSpot, ySpot, newPotential);

}

void solver::PDE_Solver::setPotentialOfBCCell(int xSpot, int ySpot, double newPotential)
{
  _bcPotDomain.setPotentialOfCell(xSpot, ySpot, newPotential);

}



double solver::PDE_Solver::potentialOfBCCell(int xSpot, int ySpot)
{
  double potentialOfBCCell = _bcPotDomain.getPotentialOfCell(xSpot, ySpot);

  return potentialOfBCCell;

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
	    //std::cout << "POT: " << x << ", "<<y<<"\n";

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

		    
		    //std::cout <<"HALP: " <<  x+i<<","<< y+j<<", "<< std::abs(calculatedPotential) << "\n";
		    memory::Cell c( x+i, y+j, std::abs(calculatedPotential));
		    adjacentCells.push_back(c);
		    
		    }

	      }
	    
	      
	    
	  }
     
      }
    }

/*  
for(int k=0; k < adjacentCells.size(); k++)
  {
		std::cout << "LISTERINO?:" << (adjacentCells.at(k)).getX() <<
		  ", " << (adjacentCells.at(k)).getY() << "\n";
		    
  }
 std::cout << "-------- \n";
*/
  
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
	  //std::cout << "LISTERINO-> XPOS:" << xInList << "; YPOS: " <<
	  // 	yInList<< "\n";
	  return true;
	}

    }
  return false;

  
}




void solver::PDE_Solver::pickRandomCell(std::vector< memory::Cell > adjacentCells, double eta)
{

  int lengthOfAdjacentCells = adjacentCells.size();
  int randomInteger;
  double totalPotential = 0;
  srand ( time(NULL) );

  
    for( int num=0; num<lengthOfAdjacentCells; num++ )
      {
	      totalPotential += (std::pow(std::abs((adjacentCells.at(num)).getPotential()), eta));
	    //std::cout << "SUSPECT-> XPOS:" << adjacentCells.at(num).getX() << "; YPOS: " <<
	    //(adjacentCells.at(num)).getY() << "\n";
      }


      std::cout<<"totalPotential:" << totalPotential<< "\n";
    // A real skunkworks attempt at developing something to select numbers
    // based off of a certain probability distribution
    randomInteger = std::rand() % 100;
    double prevNum = 0;


    
    for( int num=0; num<lengthOfAdjacentCells; num++ )
      {
	      double currentNum = (((adjacentCells.at(num)).getPotential())/totalPotential)*100;
	
	      //std::cout<<"CURRNUM:" << (((adjacentCells.at(num)).getPotential())) << "\n";

	
	      if(( randomInteger >= prevNum ) && (randomInteger < (prevNum+currentNum) ))
	        {

	   
	          this->setPotentialOfBCCell(adjacentCells.at(num).getX(),
				      adjacentCells.at(num).getY(),
				      0);

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
	      this->setPotentialOfCell(x,y,0);
	    }
	      
	}
    }
  

}







void solver::PDE_Solver::printAllPotentialValuesTerminal()
{
  double potential;
  
  for( int y=1; y<(_yTotalRange+1); y++)
    {
    for( int x=1; x<(_xTotalRange+1); x++)
      {
      
	potential = this->potentialOfBCCell(x,y);
      std::cout << potential << " : ";
    }
    std::cout << "\n";
  }
  

}


void solver::PDE_Solver::printAllPotentialValuesCSV(double currentTime, std::string filename)
{

  std::ofstream angles;

  // Using this check to see if this is the start of the simulation,
  // if it is, overwrite the data currently in the csv file
  if ( currentTime == 0 )
    {
      angles.open(filename);
    }
  else if(currentTime != 0)
    {
      angles.open(filename, std::ios::app);
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

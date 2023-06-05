

#include <iostream>
#include <exception>

#include "domain.hpp"
#include "cell.hpp"


using namespace LBSIM;



memory::Domain::Domain(int sizeX, int sizeY, int initializationValue):
  
  _totalSizeX(sizeX),
  _totalSizeY(sizeY)
{

  _cellMatrix.reserve( (sizeX * sizeY + (2*sizeX) + (2*sizeY)) );
  
		       

  for( int y=0; y<(sizeY+2); y++){
    for( int x=0; x<(sizeX+2); x++){
      

      memory::Cell c( x, y, initializationValue);
      _cellMatrix.push_back(c);
      
    }
  }
    
}

void memory::Domain::initializeDomainToUsersChoice(std::string layoutOfPotentialName){
  
  if(layoutOfPotentialName == "dot_in_circle")
    {

      int halfwayWidth = int( (_totalSizeX) / 2 );
      (_cellMatrix.at(halfwayWidth+_totalSizeX)).setPotential(0);
      (_cellMatrix.at(halfwayWidth + (2*_totalSizeX))).setPotential(0);
      (_cellMatrix.at(halfwayWidth + ( 3 * (_totalSizeX) ) ) ).setPotential(0);


      for(int i = 1 ; i < (_totalSizeX) ; i++)
	{
	  (_cellMatrix.at(i+ ( (_totalSizeY-1) * _totalSizeX ) )).setPotential(1);
	}
      
      
	
      

    }
  else if (layoutOfPotentialName == "traditional_lightning_model")
    {


    }
  else
    {
      throw std::invalid_argument("You did not select one of the possible layout selections for the potential!");
				  
    }


}



void memory::Domain::printPotentialValues()
{

  int cellNr;
  
  for( int y=0; y<(_totalSizeY+1); y++){
    for( int x=0; x<(_totalSizeX+1); x++){

      cellNr = ((y * _totalSizeX )+ x);
      
      std::cout << (_cellMatrix.at( cellNr ) ).getPotential() << " : ";
    }
    std::cout << "\n";
  }
   
  
}



int memory::Domain::getCellNr( int locationX, int locationY )
{

  int cellNr = 0;
  
  if(locationY > 0)
    {
  cellNr = (locationY-1) * _totalSizeX;

  cellNr += locationX;

    }
  else if(locationY == 0)
    {
      cellNr += locationX;

    }
  else
    {
      throw std::range_error("Tried to get cell number of a cell outside scope of potential domain array!");

    }

  return cellNr;
  
}



double memory::Domain::getPotentialOfCell(int locationX, int locationY)
{
  int cellNr = this-> getCellNr(locationX, locationY);
  double cellPotential = (_cellMatrix.at(cellNr)).getPotential();
  //std::cout << "Cell potential at (" << locationX << ", " << locationY <<
  // " ) is= " << cellPotential << "\n";

  return cellPotential;
}


void memory::Domain::setPotentialOfCell(int locationX, int locationY, double newPotentialValue)
{
    int cellNr = this-> getCellNr(locationX, locationY);
    (_cellMatrix.at(cellNr)).setPotential(newPotentialValue);

    


}
  



#include <iostream>

#include "domain.hpp"
#include "cell.hpp"


using namespace LBSIM;



memory::Domain::Domain(int sizeX, int sizeY)
{
  _totalSizeX = sizeX;
  _totalSizeY = sizeY;

  _cellMatrix.reserve(sizeX * sizeY);


  for( int y=0; y<(sizeY-1); y++){
    for( int x=0; x<(sizeX-1); x++){
      

      memory::Cell c( x, y, 0 );
      _cellMatrix.push_back(c);
      
    }
  }
    
    

}

void memory::Domain::printPotentialValues()
{

  int cellNr;
  
  for( int y=0; y<(_totalSizeY-1); y++){
    for( int x=0; x<(_totalSizeX-1); x++){

      cellNr = (y*_totalSizeX + x);
      
      std::cout << (_cellMatrix.at(cellNr)).getPotential() << " : ";
    }
    std::cout << "\n";
  }
   
  
}



int memory::Domain::getCellNr(int locationX, int locationY)
{

  int cellNr=0;
  
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
      std::cout << "The y component of location must be a non-negative number" << std::endl;

    }

  return cellNr;
  
}

  

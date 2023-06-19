

#include <iostream>
#include <exception>

#include "domain.hpp"
#include "cell.hpp"


using namespace LBSIM;



memory::Domain::Domain(int sizeX, int sizeY, double initializationValue):
  
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
  
  if(layoutOfPotentialName == "traditional_lightning_model")
    {

      int halfwayWidth = int( (_totalSizeX+2) / 2 );
      (_cellMatrix.at(halfwayWidth + (_totalSizeX+2))).setPotential(0);
      (_cellMatrix.at(halfwayWidth + (2*(_totalSizeX+2)))).setPotential(0);
      (_cellMatrix.at(halfwayWidth + ( 3 * (_totalSizeX+2) ) ) ).setPotential(0);
      (_cellMatrix.at(halfwayWidth + ( 4 * (_totalSizeX+2) ) ) ).setPotential(0);
      (_cellMatrix.at(halfwayWidth + ( 5 * (_totalSizeX+2) ) ) ).setPotential(0);


      for(int i = 1 ; i < (_totalSizeX+1) ; i++)
	      {
	        (_cellMatrix.at( i + ( (_totalSizeX+2)*_totalSizeY ) )).setPotential(10);

	      }

      
    }
  else if (layoutOfPotentialName == "circle_in_dot_model")
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

  /*
  for( int y=0; y<(_totalSizeY+2); y++){
    for( int x=0; x<(_totalSizeX+2); x++){

      cellNr = ((y * _totalSizeX )+ x);
      
      std::cout << (_cellMatrix.at( cellNr ) ).getPotential() << " : ";
    }
    std::cout << "\n";
  }
  */

  for(int i=0;i<((_totalSizeX+2) * (_totalSizeY+2));i++)
    {

      if((i%12)==0 && i!=0)
	{
	  std::cout << "\n";
	}
      std::cout << (_cellMatrix.at(i ) ).getPotential() << " : ";

    }
  std::cout << "\n";

  
}



int memory::Domain::getCellNr( int locationX, int locationY )
{

  /*
   Input the x and y location of the cell youre interested in,
   output the number that that component is in the domains vector space
  */

  int cellNr = 0;
  
  if(locationY > 0)
    {
      cellNr = (locationY) * (_totalSizeX+2);

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
  

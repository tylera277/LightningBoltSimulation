#ifndef DOMAIN_HPP
#define DOMAIN_HPP


#include <vector>


#include "cell.hpp"



namespace LBSIM
{
  namespace memory
  {


    
    class Domain
    {
    private:
      std::vector<Cell> _cellMatrix;
      int _totalSizeX, _totalSizeY;


    public:

      Domain( int xRange, int yRange, int initializationValue);

      void initializeDomainToUsersChoice(std::string layoutOfPotentialName);

      void printPotentialValues();
      
      int getCellNr(int, int);

      double getPotentialOfCell(int, int);

      void setPotentialOfCell(int xSpot, int ySpot, double newPotential);

      
      void addCell(int);
      
    
    };
   

  }//namespace memory
}// namespace LBSIM



#endif
  

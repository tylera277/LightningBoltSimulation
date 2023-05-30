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

      Domain( int, int);

      void printPotentialValues();
      
      int getCellNr(int, int);

      
      void addCell(int);
      
    
    };
   

  }//namespace memory
}// namespace LBSIM



#endif
  

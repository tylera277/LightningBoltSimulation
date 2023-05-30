

#include "init_domain.hpp"


using namespace LBSIM;


memory::Domain<double> init_domain()
{
  const int myXCells = 10;
  const int myYCells = 10;


  memory::Domain<double> myDomain(myXCells, myYCells);


  return myDomain;



}

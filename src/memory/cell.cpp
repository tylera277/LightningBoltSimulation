


#include "cell.hpp"



using namespace LBSIM;



memory::Cell::Cell(int localX, int localY,
	     double potential){
  _localX = localX;
  _localY = localY;
  _potentialValue = potential;

}

int memory::Cell::getX()
{
  return _localX;
}

int memory::Cell::getY()
{
  return _localY;
}

int memory::Cell::getPotential()
{
  return _potentialValue;
}
  

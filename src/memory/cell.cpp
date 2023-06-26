


#include "cell.hpp"
#include "../../spdlog/spdlog.h"
#include "../../spdlog/sinks/basic_file_sink.h"


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

void memory::Cell::setPotential(double newPotential)
{
  _potentialValue = newPotential;
}


double memory::Cell::getPotential()
{
  return _potentialValue;
}
  

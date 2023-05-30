

#include <vector>
#include <string>


#include "initial_conditions.hpp"



std::vector<std::vector<int>> InitialConditions::InitialZeroPotentialLayout(std::string text){
  /*
    Class for putting in the locations of the zero potential grid cells in the figure we 
    are to simulate the bolt in
  */

  std::vector<std::vector<int>> zero_potential_spot;
  
  
  if(text=="dot_in_circle")
    {
      zero_potential_spot.push_back(std::vector<int>{11,11});
    }
  else if(text=="traditional_lightning_bolt")
    {
      zero_potential_spot.push_back(std::vector<int>{0, 11});
      zero_potential_spot.push_back(std::vector<int>{1, 11});
      zero_potential_spot.push_back(std::vector<int>{2, 11});
    }

  return zero_potential_spot;

}




std::vector<std::vector<int>> InitialConditions::InitialNonZeroPotentialLayout(std::string text){
  
  std::vector<std::vector<int>> non_zero_potential_spot;
  
  
  if(text=="dot_in_circle")
    {
      
      
    }
  else if(text=="traditional_lightning_bolt")
    {
      for(int i=0;i<21;++i){
	non_zero_potential_spot.push_back(std::vector<int>{21,i});
      }
    }

  return non_zero_potential_spot;


}

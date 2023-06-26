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

      Domain( int xRange, int yRange, double initializationValue);


      /**
      * @brief Initializes the domain with the initial potential values of 
      * the user specified layout
      * 
      * @param layoutOfPotentialName the name string of the layout the user wants
      * @return the cellMatrix part of the class gets its values
      * set up, thus making it ready for computation to be performed on it
      */
      void initializeDomainToUsersChoice(std::string layoutOfPotentialName);

      
      /**
      * @brief Returns the cell number of a x & y specified location
      * 
      * @param xSpot, ySpot  the location of the desired location
      * @return the cell number of that location
      * 
      * (needed b/c technically the vector is one-dimensional, so basically
      * converting a two-d spot into a location on a 1-d list)
      */
      int getCellNr(int xSpot, int ySpot);


      /**
      * @brief Returns a cells potential at a x & y specified location
      * 
      * @param xSpot, ySpot  the location of the desired location
      * 
      * @return the potential of a cell at a specified location
      */
      double getPotentialOfCell(int xSpot, int ySpot);



      /**
      * @brief sets the potential of a cell in _cellMatrix at a specified location
      * 
      * @param xSpot, ySpot  the location of the desired location
      * @param newPotential the new potential you want to set the cell to
      */
      void setPotentialOfCell(int xSpot, int ySpot, double newPotential);


      /**
      * @brief Prints all of the cells potential values to the terminal
      * 
      * 
      * @return outputs to the terminal for the user to see
      */
      void printPotentialValues();
      
    
    };
   

  }//namespace memory
}// namespace LBSIM



#endif
  

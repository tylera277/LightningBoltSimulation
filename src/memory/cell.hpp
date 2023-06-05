#ifndef CELL_HPP
#define CELL_HPP



namespace LBSIM
{
  namespace memory
  {

    class Cell
    {
    private:
      // Cell position (Cell Number) on the Node
      int _localX;
      int _localY;
      // Value of potential at the cell
      double _potentialValue;


    public:
      
      Cell( const int, const int, double);

      
      ~Cell( )
      {
	//blah
      }

      // Get the x location of the cell under consideration
      int getX( ) ;

      // Get the y location       "           "
      int getY( ) ;

      // Set the potential
      void setPotential(double newPotential);
      
      // Get the potential        "           "
      double getPotential();

    };


  }//namespace memory
}//namespace LBSIM



#endif

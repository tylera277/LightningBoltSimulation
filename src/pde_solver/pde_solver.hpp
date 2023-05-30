


#ifndef PDE_SOLVER_H
#define PDE_SOLVER_H


#include <vector>

#include "../memory/domain.hpp"


namespace LBSIM{

  namespace pde_solver{


    class PDE_Solver
    {
    private:
      memory::Domain potDomain;
      int xTotalRange, yTotalRange;

    public:

      PDE_Solver(memory::Domain, int, int);
      
    
      memory::Domain pde_solver();

      double potentialTop();
    
    };

  }// namespace pde_solver
}//  namespace LBSIM

#endif
			       

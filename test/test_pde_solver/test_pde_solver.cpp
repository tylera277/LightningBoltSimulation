#define CATCH_CONFIG_MAIN // This tells Catch2 to provide its own main function
#include "../catch.hpp"


#include <vector>


#include "../src/pde_solver/pde_solver.hpp"
#include "../src/memory/cell.hpp"
#include "../src/memory/domain.hpp"

using namespace LBSIM;

TEST_CASE("pde solver testes", "[unit]")
{
    memory::Domain myDomain(10, 10, 0);
    memory::Domain bcDomain(10, 10, 10);

    myDomain.setPotentialOfCell(5, 5, 99);
    bcDomain.setPotentialOfCell(5, 5, 0);
    
    solver::PDE_Solver solverInstance(myDomain, bcDomain, 10, 10);


    SECTION("checkIfInListAlready")
    {
        std::vector< memory::Cell > list;

        memory::Cell c1(1, 1, 0);
        memory::Cell c2(5, 5, 0);
        list.push_back(c1);
        list.push_back(c2);

        //First two checks should be true(=1), last one should be false(=s0)
        bool status_c1 = solverInstance.checkIfInListAlready(list, 1, 1);
        bool status_c2 = solverInstance.checkIfInListAlready(list, 5, 5);
        bool status_c3 = solverInstance.checkIfInListAlready(list, 7, 7);

        REQUIRE( status_c1 == 1 );
        REQUIRE( status_c2 == 1 );
        REQUIRE( status_c3 == 0 );
    }

    SECTION("cellAdjacentToNegativeCharges")
    {
        
        memory::Cell left_top(4, 4, 0);
        memory::Cell left_middle(4, 5, 0);
        memory::Cell left_bottom(4, 6, 0);

        memory::Cell middle_top(5, 4, 0);
        memory::Cell middle_bottom(5, 6, 0);

        memory::Cell right_top(6, 4, 0);
        memory::Cell right_middle(6, 5, 0);
        memory::Cell right_bottom(6, 6, 0);

        std::vector<memory::Cell> expectedList = {left_top, left_middle, left_bottom,
        middle_top, middle_bottom, right_top, right_middle, right_bottom};

        std::vector<memory::Cell> producedList = solverInstance.cellAdjacentToNegativeCharges();
        
        for(int iterator=0; iterator<expectedList.size(); iterator++)
        {
            REQUIRE(solverInstance.checkIfInListAlready(expectedList,
            producedList.at(iterator).getX(), producedList.at(iterator).getY()) == 1);


        }
    }

}


#define CATCH_CONFIG_MAIN
#include "catch.hpp"




#include "../src/memory/domain.hpp"
#include "../src/memory/cell.hpp"

using namespace LBSIM;



TEST_CASE("memory domain tests", "[unit]")
{

  memory::Domain dmn(10,10,1);
  
  SECTION("getCellNr")
    {
      REQUIRE(dmn.getCellNr(0,0) == Approx(0));

      REQUIRE(dmn.getCellNr(11,0) == Approx(11));

      REQUIRE(dmn.getCellNr(0,1) == Approx(12));

      REQUIRE(dmn.getCellNr(11,11) == Approx(143));

    }

}

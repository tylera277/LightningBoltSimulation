
#include <string>

namespace LBSIM{

    namespace simParams{

        
        // Size of grid that the user wants to simulate
        const int xTotalCells = 50;
        const int yTotalCells = 50;

        // User chooses which model they want to simulate
        const std::string initialBoardLayout = "traditional_lightning_model";
        // "circle_in_dot_model" - this model hasnt been implemented yet

        // Simulation length and increment details
        const int simulationLength = 100;
        const int simulationIncrement = 1;
        const int simulationStartingPoint = 0;

        // The condition which marks where I call the results not changing
        // and final
        const double ceaseCondition = 0.00005;

        // A user defined parameter which should in theory, 
        // adjust the branching of the lightning bolts
        // (but not working properly at the moment)
        const double eta = 2;

        // File where you want to print the results out to 
        const std::string outputPotentialFile = "../src/outputData/24jun2023_pot_data.csv";
        const std::string outputBCFile = "../src/outputData/24jun2023_BC_data.csv";


        // File where youre logging errors & general running info to
        const std::string outputErrorFile = "../src/logs/basic_log.txt";




    }

}
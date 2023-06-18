
#include <string>

namespace LBSIM{

    namespace simParams{

        
        // Size of grid that the user wants to simulate
        const int xTotalCells = 100;
        const int yTotalCells = 100;

        // User chooses which model they want to simulate
        const std::string initialBoardLayout = "traditional_lightning_model";
        // "circle_in_dot_model" - this model hasnt been implemented yet

        // Simulation length and increment details
        const int simulationLength = 150;
        const int simulationIncrement = 1;
        const int simulationStartingPoint = 0;

        // A user defined parameter which should in theory, 
        // adjust the branching of the lightning bolts
        const double eta = 1;

        // File where you want to print the results out to 
        const std::string outputFile = "../src/outputData/10jun2023_data.csv";




    }

}
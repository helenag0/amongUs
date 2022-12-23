//
//  IDENTIFIER  = 9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include "getopt.h"
#include "xcode_redirect.hpp"
#include "partC.hpp"
#include <iomanip>

using namespace std;

char mode;

void printHelp() {
    //implement
    cout << "Accetable modes: " << '\n';
    cout << "MSP: Find the minimum spanning tree (MST) of the map." << '\n';
    cout << "FASTTSP: Find a fast, but not necessarily optimal, solution to the TSP." << '\n';
    cout << "OPTTSP: Find the optimal solution to the TSP." << '\n';
    exit(0);
}



void getMode(int argc, char * argv[]) {
    
//        bool modeSpecified = false;
        opterr = false;
        int choice;
        int option_index = 0;
        option long_options[] = {
            {"help", no_argument, nullptr, 'h'},
            {"mode", required_argument, nullptr, 'm'},
            { nullptr, 0,                 nullptr, '\0' }
        };
    
        while ((choice = getopt_long(argc, argv, "hm:", long_options, &option_index)) != -1) {
            switch (choice) {
            
            case 'm':
                    
                    mode = *optarg;
                    if(mode != 'M' && mode != 'F' && mode != 'O') {
                        cerr << "Error: Invalid mode" << endl;
                        exit(1);
                    }
                    break;
                    
            case 'h':
                    
                    printHelp();
                    break;
    
            default:
                    
                    cerr << "Error: Invalid command line option" << endl;
                    exit(1);
            } // switch
        } // while
    
}


int main(int argc, char *argv[]) {
//int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << std::setprecision(2); //Always show 2 decimal places
    cout << std::fixed; //Disable scientific notation for large numbers
    
    xcode_redirect(argc, argv);
    getMode(argc, argv);
    partA a;
    if(mode == 'M') {
        a.read_input();
        a.prims_alg();
        a.output();
    }
    if(mode == 'F') {
        a.read_input();
        partB b;
//        b.read_input();
        b.algorithm(a.coords_in);
        b.output();
    }
    if(mode == 'O') {
        partC c;
        c.start();
        c.output();
    }
    
    return 0;
    
}



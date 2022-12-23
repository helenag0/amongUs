//
//  partC.hpp
//  project4
//  9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7
//  Created by Helena Grobel on 11/23/22.
//

#ifndef partC_hpp
#define partC_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <limits>
#include "partB.hpp"

#endif /* partC_hpp */

using namespace std;

class partC {

public:
    
    partC() : coords_in(), prim(), path(std::vector<uint32_t>()), bestPath(std::vector<uint32_t>()), bestDistance(0.0), currentPath(0.0), distance_matrix()
      {

      }
    
    std::vector<partA::coordinate> coords_in;
    std::vector<partA::prim_info> prim;
    vector<uint32_t> path;
    std::vector<uint32_t> bestPath;
    double bestDistance;
    double currentPath;
    void start();
    void genPerms(vector<uint32_t> &path, size_t permLength);
    bool promising(vector<uint32_t> &path, size_t permLength);
    std::vector<std::vector<double>> distance_matrix;
    void output();




};

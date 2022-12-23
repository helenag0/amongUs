//
//  partB.hpp
//  project4
//  9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7
//  Created by Helena Grobel on 11/23/22.
//

#ifndef partB_hpp
#define partB_hpp

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
#include "partA.hpp"

#endif /* partB_hpp */

using namespace std;


class partB {
    
private:
    
//    struct coordinate {
//        int x;
//        int y;
//        char room_type; //l = lab, o = outer, d = decontam.
////        bool visited = false;
//    };
    
//    std::vector<coordinate> coords_in;
    
public:
    
//    void read_input();
    void output();
    void algorithm(std::vector<partA::coordinate> &coords_in);
    double squared_distance(std::vector<partA::coordinate> coords_in, uint32_t idx_1, uint32_t idx_2);
    double final_dist;
    std::vector<uint32_t> final_path;
    
    struct compare {
      bool operator()(const std::pair<double, uint32_t>& a, const std::pair<double, uint32_t>& b) const {
        return a.first > b.first;
      }
    };
    
    

    
    
};

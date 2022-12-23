//
//  partA.hpp
//  project4
//  9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7
//  Created by Helena Grobel on 11/23/22.
//

#ifndef partA_hpp
#define partA_hpp

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

#endif /* partA_hpp */

using namespace std;


class partA {
    
private:
    
//    struct coordinate {
//        int x;
//        int y;
//        char room_type; //l = lab, o = outer, d = decontam.
//        bool operator==(const coordinate &c) {
//            return (x == c.x && y == c.y && room_type == c.room_type);
//        }
//    };
//
//    struct prim_info {
//        bool visited;
//        double edge_weight;
//        int predecessor;
////        bool has_pred;
//    };
    
    
public:
    
    struct coordinate {
        int x;
        int y;
        char room_type; //l = lab, o = outer, d = decontam.
//        bool operator==(const coordinate &c) {
//            return (x == c.x && y == c.y && room_type == c.room_type);
//        }
    };
    
    struct prim_info {
        bool visited;
        double edge_weight;
        uint32_t predecessor;
//        bool has_pred;
    };
    
    void read_input();
    void prims_alg();
    double squared_distance(uint32_t prim_idx, uint32_t min_idx);
    void output();
    double weight;
    std::vector<pair<uint32_t, uint32_t>> out;
    std::vector<coordinate> coords_in;
    std::vector<prim_info> prim;
    

    
    
    
};

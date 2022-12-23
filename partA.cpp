//
//  partA.cpp
//  project4
//  9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7
//  Created by Helena Grobel on 11/23/22.
//

#include "partA.hpp"
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
#include <algorithm>
#include <cmath>

void partA::read_input() {
    
    size_t vtx_tot;
    cin >> vtx_tot;
    coords_in.reserve(vtx_tot);
    prim.reserve(vtx_tot);
    for(uint32_t i = 0; i < vtx_tot; i++) {
        coordinate c;
        prim_info p;
        p.visited = false;
        p.edge_weight = numeric_limits<double>::infinity();
        cin >> c.x;
        cin >> c.y;

        if(c.x < 0 && c.y < 0) {
            c.room_type = 'l';
        }
        else if((c.x == 0 && c.y <= 0) || (c.y == 0 && c.x <= 0)) {
            c.room_type = 'd';
        }
        else {
            c.room_type = 'o';
        }
        
        
        coords_in.push_back(c);
        prim.push_back(p);
    }
    
    
}

void partA::prims_alg() {
    
    uint32_t min_index = 0;
//    uint32_t temp_idx = 0;
//    int total = 0;
    prim[0].edge_weight = 0;
    double temp_min_dist = numeric_limits<double>::infinity();
    
    for(uint32_t i = 0; i < prim.size(); i++) {
        temp_min_dist = numeric_limits<double>::infinity();
        
        for(uint32_t j = 0; j < prim.size(); j++) {
            
            if(prim[j].visited == false) {
                if(prim[j].edge_weight < temp_min_dist) {
                    min_index = j;
                    temp_min_dist = prim[j].edge_weight;
                }
                
            }
        }
        prim[min_index].visited = true;
//        temp_min_dist = numeric_limits<double>::infinity();

        for(uint32_t a = 0; a < prim.size(); a++) {
            if(prim[a].visited == false) {
                double new_dist = squared_distance(min_index, a);
                if(prim[a].edge_weight > new_dist) {
                    prim[a].edge_weight = new_dist;
                    prim[a].predecessor = min_index ;
//                    temp_min_dist = new_dist;
//                    temp_idx = a;
                }
            }
        }
        
        if(temp_min_dist != numeric_limits<double>::infinity()) {
            weight += sqrt(temp_min_dist);
        }
        
        
    }
    
    
    
}

double partA::squared_distance(uint32_t prim_idx, uint32_t min_idx) {
    
    if ((coords_in[prim_idx].room_type == 'l' && coords_in[min_idx].room_type == 'o') || (coords_in[prim_idx].room_type == 'o' && coords_in[min_idx].room_type == 'l')) {
        
        return numeric_limits<double>::infinity();
        
    }
    
    double x_min = coords_in[min_idx].x;
    double y_min = coords_in[min_idx].y;
    double x_prim = coords_in[prim_idx].x;
    double y_prim = coords_in[prim_idx].y;
    double total = 0;
    total += double((x_min - x_prim) * (x_min - x_prim));
    total += double((y_min - y_prim) * (y_min - y_prim));
    
    return double(total);
}

void partA::output() {

    cout << weight << '\n';
    for(uint32_t i = 1; i < prim.size(); i++) {
        cout << min(i, prim[i].predecessor) << " " << max(i, prim[i].predecessor) << '\n';
    }
    
    
}

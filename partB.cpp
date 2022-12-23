//
//  partB.cpp
//  project4
//  9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7
//  Created by Helena Grobel on 11/23/22.
//

#include "partB.hpp"
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



void partB::algorithm(std::vector<partA::coordinate> &coords_in) {
    
    
    
    final_path.reserve(coords_in.size() + 1);
    final_path.push_back(0);
    final_path.push_back(1);
    final_path.push_back(2);
    final_path.push_back(0);
    final_dist = sqrt(squared_distance(coords_in, 0, 1)) + sqrt(squared_distance(coords_in, 1, 2)) + sqrt(squared_distance(coords_in, 2, 0));
    
    for(uint32_t i = 3; i < coords_in.size(); i++) {
        
//        std::priority_queue<pair<double, uint32_t>, std::vector<double>, std::greater<double>> distances;
        std::priority_queue<std::pair<double, uint32_t>, std::vector<std::pair<double, uint32_t>>, compare> distances;
//        double temp_size = 0;
//        uint32_t temp_index = 0;
//        double min = numeric_limits<double>::infinity();
        
        for(uint32_t j = 0; j < static_cast<uint32_t>(final_path.size() - 1); ++j) {
//        for(uint32_t j = static_cast<uint32_t>(final_path.size() - 1); j > 0; --j) {
//            temp_size = double(sqrt(squared_distance(coords_in, final_path[(j + 1)], i)) + sqrt(squared_distance(coords_in, i, final_path[j])) - sqrt(squared_distance(coords_in, final_path[(j + 1)], final_path[j])));
            distances.push({double(sqrt(squared_distance(coords_in, final_path[(j + 1)], i)) + sqrt(squared_distance(coords_in, i, final_path[j])) - sqrt(squared_distance(coords_in, final_path[(j + 1)], final_path[j]))), j});
//            double dist1 = sqrt(squared_distance(coords_in, final_path[(j + 1)], i)); // i to k
//            double dist2 = sqrt(squared_distance(coords_in, i, final_path[j])); // k to j
//            double dist3 = sqrt(squared_distance(coords_in, final_path[(j + 1)], final_path[j])); // i to j
//            temp_size = double(dist1 + dist2 - dist3);
//            if(temp_size < min) {
//                temp_index = j + 1;
//                min = temp_size;
//
//            }
        }
        pair<double, uint32_t> end = distances.top();
//        final_dist += min;
        final_dist += end.first;
//        final_path.insert((final_path.begin() + temp_index), i);
        final_path.insert((final_path.begin() + (end.second + 1)), i);
    }
  
}

//output = list of indices of rooms (ex. 0 2 3 = room 0 --> room 2 --> room 3)

void partB::output() {
    
    cout << final_dist << '\n';
    
    for(uint32_t i = 0; i < final_path.size() - 1; i++) {
        cout << final_path[i] << " ";
    }
    cout << '\n';
}


double partB::squared_distance(std::vector<partA::coordinate> coords_in, uint32_t idx_1, uint32_t idx_2) {
    
//    double x_2 = coords_in[idx_2].x;
//    double y_2 = coords_in[idx_2].y;
//    double x_1 = coords_in[idx_1].x;
//    double y_1 = coords_in[idx_1].y;
//    double total = 0;
//    total += (x_2 - x_1) * (x_2 - x_1);
//    total += (y_2 - y_1) * (y_2 - y_1);
    
    double total = 0;
    total += (coords_in[idx_2].x - coords_in[idx_1].x) * (coords_in[idx_2].x - coords_in[idx_1].x);
    total += (coords_in[idx_2].y - coords_in[idx_1].y) * (coords_in[idx_2].y - coords_in[idx_1].y);
    
    return total;
}





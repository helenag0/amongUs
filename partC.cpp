//
//  partC.cpp
//  project4
//  9B734EC0C043C5A836EA0EBE4BEFEA164490B2C7
//  Created by Helena Grobel on 11/23/22.
//

#include "partC.hpp"
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
#include <cmath>


//partC::partC()
//    : c(C)
//{}

void partC::start() {

    partB b;
    partA a;
    a.read_input();
    coords_in = a.coords_in;
    prim = a.prim;
//    b.read_input();
    b.algorithm(a.coords_in);
    // 2. Run part B to get an upper bound of the distance, and store it in some sort of bestDistance variable,
    // and store the path in a bestPath variable.
    bestDistance = b.final_dist;
    bestPath = b.final_path;
    bestPath.pop_back();
    std::vector<uint32_t> curr_path = bestPath;

    // 1. Start by constructing a distance matrix so that distance lookups are efficient.
    
    for(uint32_t i = 0; i < coords_in.size(); i++) {
        std::vector<double> row;
        for(uint32_t j = 0; j < coords_in.size(); j++) {
//            distance_matrix[i][j] = sqrt(b.squared_distance(coords_in, i, j));
            
            row.push_back(sqrt(b.squared_distance(coords_in, i, j)));
        }
        distance_matrix.push_back(row);
    }

    // 3. Call genPerms(1)

    genPerms(curr_path, 1);

}

void partC::genPerms(vector<uint32_t> &path, size_t permLength) {

    // 4.  If permLength == path.size(), if it's less than bestDistance
    // (taking into account the final edge), update bestDistance and bestPath.

    if (permLength == path.size()) {
        currentPath += distance_matrix[path.size() - 1][0];
        if(currentPath < bestDistance) {
            bestDistance = currentPath;
            bestPath = path;
            return;
        }
        // Do something with the path
        currentPath -= distance_matrix[path.size() - 1][0];
        return;
    }  // if ..complete path

    //  Call promising().

    if (!promising(path, permLength)) {
        return;
    }  // if ..not promising
    

    for (size_t i = permLength; i < path.size(); ++i) { //Iterate over the remaining rooms not part of the subtour, adding to the running total.
        swap(path[permLength], path[i]);
        //Recursively call genPerms(permLength + 1).
        genPerms(path, permLength + 1);
        //Swap the rooms in the path vector back, subtracting from the running total.
        swap(path[permLength], path[i]);
    }  // for ..unpermuted elements
}  // genPerms()

//Print bestDistance and bestPath.

// promising function helps prune impossible solutions

bool partC::promising(vector<uint32_t> &path, size_t permLength) {
    
    double distance = distance_matrix[path[permLength - 1]][path[permLength]];

    // Initialize the prim vector and set the visited flag for the first node to true
    prim[path[permLength - 1]].visited = true;

        // Compute the minimum spanning tree for the path using Prim's algorithm
        for (uint32_t i = 1; i < path.size(); ++i) {
            uint32_t min_index = 0;
            double temp_min_dist = numeric_limits<double>::infinity();
            for (uint32_t j = 1; j < path.size(); ++j) {
                if (!prim[j].visited) {
                    double new_dist = distance_matrix[path[i - 1]][j];
                    if (prim[j].edge_weight > new_dist) {
                        prim[j].edge_weight = new_dist;
                    }
                    if (prim[j].edge_weight < temp_min_dist) {
                        min_index = j;
                        temp_min_dist = prim[j].edge_weight;
                    }
                }
            }
            prim[min_index].visited = true;

            // Update the total distance of the path
            distance += temp_min_dist;
        }
//    distance += distance_matrix[path[path.size() - 1]][path[0]];
    distance += distance_matrix[path[path.size() - 1]][0];
    
//    distance += distance_matrix[permLength - 1][permLength];
//    currentPath = distance;

    if(distance < bestDistance)  {
        currentPath = distance;
        return true;
    }
    return false;
     
//    return distance < bestDistance;
    

}
    
    
    //  Add the two connecting arms, one from the start of the subtour and one from the end of the subtour, to the closest room in the MST.
    //  If the total distance of that is less than bestDistance, return true. Otherwise, return false.

    
//    check if current_distance + additional_distance >= upper_bound
//     upper bound is from part b
//     current_distance + additional distance is like your total would be (future) distance if you were to continue with your path
//     additional distance = part_A_distance + last_edges
//     last_edges = what connects the MST nodes (not in the path) to your current nodes (that you already have in your path)

void partC::output() {
    
    cout << bestDistance << '\n';
    
    for(uint32_t i = 0; i < bestPath.size(); i++) {
        cout << bestPath[i] << " ";
    }
}
    


#include<iostream>
#include<vector>
using namespace std;

// Back-end complete function Template for C++

class Solution {
  public:
    // Function to perform Bellman-Ford algorithm to find the shortest distance from a source node to all other nodes in a weighted graph.
    vector<int> bellman_ford(int N, vector<vector<int>>& edges, int src) {
        int inf = 100000000;
        vector<int> dist(N, inf); // Initialize distance array with infinity.

        dist[src] = 0; // Set distance of source node to 0.

        // Run the relaxation process N-1 times.
        for (int i = 1; i <= N - 1; i++) {
            for (auto it : edges) {
                // If there is a shorter path from the source node to the current node, update the distance.
                if (dist[it[0]]!=inf && dist[it[0]] + it[2] < dist[it[1]]) {
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }


        for (auto it : edges) {
            // If there is a negative cycle, return -1.
            if (dist[it[0]]!=inf && dist[it[0]] + it[2] < dist[it[1]]) {
                return {-1};
            }
        }

        
        return dist;
        
    }
};

//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  private:
    bool detectCycle(vector<int> adj[], int src, int parent, int vis[]){
        vis[src] = 1;
        for(auto adjnode: adj[src]){
            if(!vis[adjnode]){
                if(detectCycle(adj, adjnode, src, vis)) return true;
            }
            else if(adjnode!=parent){
                return true;
            }
        }
        return false;
        
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
               if(detectCycle(adj, i, -1, vis)) return true;
            }
        }
        return false;
    }
};
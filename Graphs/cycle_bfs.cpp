//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
    private:
        bool detectCycle(vector<int> adj[], int src, int vis[]){
            //{src, parent}
            queue<pair<int, int>>q;
            q.push({src,-1});
            vis[src] = 1;
            
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto adjnode : adj[node]){
                    //if an adjacent node is already visited and its not the parent, cycle exists
                    if(!vis[adjnode]){
                        q.push({adjnode, node});
                        vis[adjnode] = 1;
                    }
                    else if(parent != adjnode){
                        return true;
                    }
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
                if(detectCycle(adj, i, vis)) return true;
                }
            }
            return false;
        }
};
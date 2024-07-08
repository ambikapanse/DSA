//https://leetcode.com/problems/is-graph-bipartite/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool dfsCheck(vector<vector<int>>& graph, int node, int col, vector<int>& color){
        color[node] = col;
        for(auto adjnode:graph[node]){
            if(color[adjnode]==-1){
                if(dfsCheck(graph, adjnode, !col, color)==false)
                return false;
            }else if(color[adjnode]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0; i<graph.size(); i++){
            if(color[i]==-1){
                if(dfsCheck(graph, i, 0, color)==false)
                return false;
            }
        }
        return true;
    }
};
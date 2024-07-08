//https://leetcode.com/problems/course-schedule/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses; 
        vector<int>graph[V];
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>inDegree(V,0);
        for(int i=0; i<V; i++){
            for(auto it: graph[i])
            inDegree[it]++;
        }

        queue<int>q;
        for(int i=0 ;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto adjnode : graph[node]){
                inDegree[adjnode]--;
                if(inDegree[adjnode]==0){
                    q.push(adjnode);
                }
            }
        }

        if(topo.size()==V)
        return true;

        return false;
    }
};
//https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int index=-1;
	    int mini=m;
	    for(int i=0;i<n;i++){
	        if(mini>lower_bound(arr[i].begin(),arr[i].end(),1) - arr[i].begin()){
	            mini = lower_bound(arr[i].begin(),arr[i].end(),1) - arr[i].begin();
	            index = i;
	        }
	    }
	    return index;
	}

};
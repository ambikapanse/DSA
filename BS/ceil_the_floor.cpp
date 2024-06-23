// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM
#include<iostream>
#include<vector>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int s=0;
	int e = a.size()-1;
	int floor = -1;
	int ceil = -1;

	//floor
	while(s<=e){
		int mid = s+(e-s)/2;
		if(a[mid]<=x){
			floor = a[mid];
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	s=0,e=a.size()-1;
	//ceil
	while(s<=e){
		int mid = s+(e-s)/2;
		if(a[mid]>=x){
			ceil = a[mid];
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}

	pair<int,int>p;
	p.first = floor;
	p.second = ceil;
	return p;
}
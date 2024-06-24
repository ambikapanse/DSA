//https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
#include<iostream>
#include<vector>
using namespace std;

int canPaint(vector<int> &boards, int k, int mid){
    int hours_taken=0, painters=1;
    for(int i=0; i<boards.size();i++){
        if(hours_taken+boards[i]<=mid){
            hours_taken+=boards[i];
        }else{
            painters++;
            hours_taken = boards[i];
        }
        //check for no. of painters
        if(painters>k){
            return 0;
        }
    }
    return 1;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = *max_element(boards.begin(),boards.end());
    int e = accumulate(boards.begin(),boards.end(),0);
    int ans = e;
    while(s<=e){
        int mid = s+(e-s)/2;

        if(canPaint(boards, k, mid)){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}
//https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=SUBMISSION
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int canRead(vector<int>& arr, int m, int mid){
    int pages_read=0,students=1;
    for(int i=0;i<arr.size();i++){
        if (mid >= pages_read + arr[i]) {
            pages_read += arr[i];
        }
        else{
            students++;
            pages_read = arr[i];
        }
        //check if students satisifed
        if (students > m) {
            return 0;
        }
    }
    return 1;
}


int findPages(vector<int>& arr, int n, int m) {
    if(m>n)
    return -1;
    int s=*max_element(arr.begin(),arr.end());
    int e=accumulate(arr.begin(),arr.end(),0);
    int ans = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(canRead(arr,m,mid)){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}
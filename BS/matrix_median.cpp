//https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//User function template for C++

class Solution{   
public:
    int func(vector<vector<int>> &matrix, int R, int C, int mid){
        int count=0;
        for(int i=0; i<R; i++){
            count += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int s=INT_MAX;
        int e=INT_MIN;
        for(int i=0;i<R;i++){
            s = min(s, matrix[i][0]);
            e = max(e, matrix[i][C-1]);
        }
        
        int smallerThanMedian = (R*C)/2;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            int smallEquals = func(matrix, R, C, mid);
            
            if(smallEquals<=smallerThanMedian){
                s = mid+1;
            }else{
                e = mid-1;
            }
            
        }
        return s;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
//https://www.geeksforgeeks.org/problems/aggressive-cows/0

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    int canPlace(vector<int> &stalls, int k, int mid){
        //we start with the first cow at index 0.
        int cows=1;
        int last=stalls[0];
        
        for(int i=0;i<stalls.size();i++){
            //if minimum distance (mid) available to place cow
            if(mid<=stalls[i]-last){
                cows++;
                last = stalls[i];
            }
            //check if all cows placed
            if(cows>=k)
            return 1;
        }
        return 0;
    }
    

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int s=1;
        int e=stalls[n-1]-stalls[0]; //maximum dist possible between cows
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(canPlace(stalls,k,mid)){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return e;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
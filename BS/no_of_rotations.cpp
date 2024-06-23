// https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int s=0;
	    int e=n-1;
	    int ans = INT_MAX; //point of rotation
	    int count=0; //index of the point of rotation
	    
	    while(s<=e){
	        int mid = s+(e-s)/2;
	        //left half is sorted, search right half
	        if(arr[s]<=arr[mid]){
	            if(arr[s]<ans){
	                count = s;
	            }
	            ans = min(ans, arr[s]);
	            s = mid+1;
	        }
	        //right half is sorted, search left half
	        else{
	            if(arr[mid]<ans){
	                count = mid;
	            }
	            ans = min(ans,arr[mid]);
	            e = mid-1;
	        }
	    }
	    
	    return count;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
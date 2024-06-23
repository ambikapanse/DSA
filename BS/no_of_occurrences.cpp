// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int s=0;
	    int e=n-1;
	    int first=-1;
	    int last=-1;
	    int count=0;
	    
	    //find first occurrence
	    while(s<=e){
	        int mid = s+(e-s)/2;
	        if(arr[mid]==x){
	            first = mid;
	            e = mid-1;
	        }
	        else if(arr[mid]>x){
	            e = mid-1;
	        }else{
	            s = mid+1;
	        }
	    }
	    
	    s=0, e=n-1;
	     //find last occurrence
	    while(s<=e){
	        int mid = s+(e-s)/2;
	        if(arr[mid]==x){
	            last = mid;
	            s = mid+1;
	        }
	        else if(arr[mid]>x){
	            e = mid-1;
	        }else{
	            s = mid+1;
	        }
	    }
	    if(first==-1 && last==-1)
	    return count;
	    
	    count = last-first+1;
	    return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
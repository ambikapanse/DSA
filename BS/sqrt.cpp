//https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root
#include<iostream>
#include<vector>
using namespace std;

// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        int s=1;
        int e=x;
        long long ans;
        
        while(s<=e){
            long long mid = s+(e-s)/2;
            
            if(mid*mid<=x){
                ans = mid;
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int isAnswer(int mid, int m, int n){
	    long long ans=1;
	    for(int i=0;i<n;i++){
	        if(ans>m)
	        return 0;
	        ans*=mid;
	    }
	    if(ans==m)
	    return 1;
	    else if(ans>m)
	    return 0;
	    else
	    return 2;
	}
	
	int NthRoot(int n, int m)
	{
	    int s = 1;
	    int e = m;
	    int ans=-1;
	    
	    while(s<=e){
	        long long mid = s+(e-s)/2;
	        
	        if(isAnswer(mid,m,n)==1){
	            ans = mid;
	            break;
	        }
	        else if(isAnswer(mid,m,n)==2){
	            s = mid+1;
	        }else{
	            e = mid-1;
	        }
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
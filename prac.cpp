#include<iostream>
#include<vector>
using namespace std;


void sieve(int n, int m, vector<int>& allPrimes){
    cout<<"running.."<<endl;
    vector<bool>prime(n+1, true);

    for(int i=2; i*i<=n; i++){
        if(prime[i]==true){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }

    int cnt=0;
    for(int i=2; i<n+1; i++){
        if(prime[i]){
            cout<<"allowed: "<<i<<endl;
            allPrimes.push_back(i);
            cnt++;
        }
        if(cnt==m){
            return;
        }
    }
    return;
}

int minPrime(int n, int m){
    cout<<"running.."<<endl;
    vector<int>allPrimes;
    sieve(n, m, allPrimes);

    vector<int>dp(n+1,1e6);
    dp[0] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        for(int j=0; j<allPrimes.size(); j++){
            if(allPrimes[j]>i)
            break;
            dp[i] = min(dp[i], 1+dp[i-allPrimes[j]]);
        }
    }
    
    return dp[n];
}

int main(){
    cout<<"running.."<<endl;
    int result = minPrime(10,1);
    cout<<"result: "<<result<<endl;
}
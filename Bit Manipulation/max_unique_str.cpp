//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void solve(int index, int temp, int &result, vector<int>& unique){
        result = max(result, __builtin_popcount(temp));

        //check all combinations
        for(int i=index; i<unique.size(); i++){
            //if temp and the next string does not have duplicates
            if((temp&unique[i])==0){
                //So concatenate them : temp | unique[i]
                solve(i+1, temp|unique[i], result, unique);
            }
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int>unique;
        for(string &s: arr){
        
            //put all characters of the string into a set
            unordered_set<char>st(begin(s), end(s));
            
            //if size of set not equal to size of string => duplicate
            if(st.size()!=s.size()){
                continue;
            }

            //else, convert into binary
            int val=0;
            for(char &c: s){
                val = val|1<<(c-'a');
            }

            unique.push_back(val);
        }

        int result=0;
        solve(0, 0, result, unique);

        return result;
    }
};
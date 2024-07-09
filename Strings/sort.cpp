#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string str="";
        map<char, int> mp;
        for(auto it: s){
            mp[it]++;
        }
        vector<pair<char,int>> freq;
        for(auto& it : mp){
            freq.push_back(it);
        }

        sort(freq.begin(), freq.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        for(int i=0; i<freq.size(); i++){
            for(int j=0; j<freq[i].second; j++){
                str+=freq[i].first;
            }
        }
        return str;
    }
};
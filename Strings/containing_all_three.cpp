//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int i=0,j=0,count=0;

        unordered_map<char, int> mp;

        while(j<n)
        {
            mp[s[j]]++;

            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
            {
                count += (n - j);

                //shrinking the window
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};
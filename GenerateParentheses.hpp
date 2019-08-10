#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/generate-parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string temp;
        helper(result,temp,0,0,n);
        return result;
    }
    void helper(vector<string>& result,string str,int l,int r,int n)
    {
        if (str.size()==n*2)
        {
            result.push_back(str);
            return;
        }
        if (l<n)
        {
            helper(result,str+"(",l+1,r,n);
        }
        if (r<l)
        {
            helper(result,str+")",l,r+1,n);
        }
    }
};
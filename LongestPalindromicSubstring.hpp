// https://leetcode.com/problems/longest-palindromic-substring
// 日常dp
#include<iostream>
using namespace std;
    class Solution {
    public:
        string longestPalindrome(string s) {
            int l=s.length();
            if (l<=1)
            {
                return s;
            }
            bool dp[l][l+1];//l+1 overtail.begin,end
            int b=0,e=1;
            for(int i=0;i<l;i++)
            {
                for (int j=0;j<l+1;j++)
                {
                    dp[i][j]=false;
                }
            }
            for (int i=0;i<l;i++)
            {
                dp[i][i]=true;
                dp[i][i+1]=true;
            }
            for (int i=2;i<=l;i++)
            {
                for (int j=0;j+i<=l;j++)
                {
                    if(s[j]==s[j+i-1]&&dp[j+1][j+i-1])
                    {
                        dp[j][j+i]=true;
                        if((e-b)<i)
                        {
                            e=i+j;
                            b=j;
                        }
                    }
                }
            }
            return s.substr(b,e-b);
        }
    };
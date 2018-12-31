#include <string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl=s.length();
        int pl=p.length();
        bool dp[sl+1][pl+1];
        //dp[0][0]
        dp[0][0]=true;
        //dp[0][1]~dp[0][pl]
        for (int i=1;i<pl+1;i++)
        {
            dp[0][i]=false;
            if (p[i-1]=='*')
            {
                dp[0][i]=dp[0][i-2];
            }
        }
        //s[i-1]p[j-1]
        for (int i=1;i<sl+1;i++)
        {
            dp[i][0]=false;
            for (int j=1;j<pl+1;j++)
            {
                if (p[j-1]<='z'&&p[j-1]>='a')//alpha
                {
                    dp[i][j]=false;
                    if (p[j-1]==s[i-1])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                }
                else if (p[j-1]=='.')//.
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else//*
                {
                    //one
                    dp[i][j]=dp[i][j-1];
                    //zero
                    if(dp[i][j-2]==true)
                    {
                        dp[i][j]=true;
                    }
                    //two or more
                    else if  (p[j-2]=='.'||p[j-2]==s[i-1])//equal
                    {
                        if (dp[i-1][j]==true||dp[i-1][j-1]==true)//one or more
                        {
                            dp[i][j]=true;
                            
                        }
                    }
                }
            }
        }
        for (int i=0;i<sl+1;i++)
        {
            for (int j=0;j<pl+1;j++)
            {
                cout <<dp[i][j]<<" ";

            }
            cout <<endl;
        }
        return dp[sl][pl];

    }
};
int main()
{
    string s="mississippi";
    string p="mis*is*p*.";
    Solution a;
    a.isMatch(s,p);

}

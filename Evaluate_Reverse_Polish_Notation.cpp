#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size()==0)
        {
            return 0;
        }
        int l=tokens.size();
        int nums[l];
        int size=0;
        for(auto &s:tokens)
        {
            int temp=judgeOper(s);
            if (temp==0)
            {
                nums[size++]=sTOi(s);
            }
            else
            {
                int num1=nums[--size];
                int num2=nums[--size];
                if (temp==1)
                {
                    num2+=num1;
                }
                else if (temp==2)
                {
                    num2-=num1;
                }
                else if (temp==3)
                {
                    num2*=num1;
                }
                else
                {
                    num2/=num1;
                }
                nums[size++]=num2;
            }
        }
        return nums[0];
    }
    int sTOi(const string & s)
    {
        int m=1;
        int i=0;
        if (s[0]=='-')
        {
            m=-1;
            i=1;
        }
        int result=0;
        for (;i<s.size();i++)
        {
            result=result*10+s[i]-'0';
        }
        result*=m;
        return result;
    }
    int judgeOper(const string &s)
    {
        if (s.size()>1)
        {
            return 0;
        }
        if (s=="+")
        {
            return 1;
        }
        if (s=="-")
        {
            return 2;
        }
        if (s=="*")
        {
            return 3;
        }
        if (s=="/")
        {
            return 4;
        }
        return 0;
    }
};
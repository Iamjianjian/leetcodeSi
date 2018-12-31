#include <vector>
#include <string.h>
#include <map>
using namespace std;

class Solution {
public:
    //鸽巢原理，去重之后桶排序，最大距离必在桶之间
    int maximumGap(vector<int>& nums) {
        // remove duplicate
        if (nums.size()<1)
        {
            return 0;
        }
        map<int,bool> mark;
        int tail=nums.size()-1;
        int head=0;
        while (head<tail)
        {
            int temp1=nums[head];
            auto it=mark.find(temp1);
            if(it==mark.end())
            {
                mark[temp1]=true;
                head++;
            }
            else
            {
                int tempInt=nums[tail];
                nums[tail]=nums[head];
                nums[head]=tempInt;
                tail--;
            }
        }
        auto it=mark.find(nums[head]);
        if (it==mark.end())
        {
            head++;
        }
        nums.erase(nums.begin()+head,nums.end());
        if(nums.size()<2)      
        {
            return 0;
        }
        if (nums.size()==2)
        {
            return abs(nums[0]-nums[1]);
        }
        int l=nums.size();
        int max=nums[0],min=nums[0];
        for (auto &i:nums)
        {
            if (max<i)
            {
                max=i;
            }
            else if (min>i)
            {
                min=i;
            }
        }
        int buksmall[l];
        int bukbig[l];
        // memset(bukbig,-1,l);
        // memset(buksmall,-1,l);
        for (int i=0;i<l;i++)
        {
            bukbig[i]=-1;
            buksmall[i]=-1;
        }
        int mod=(max-min+1)/(l-1);
        if ((max-min+1)%(l-1))
        {
            mod+=1;
        }
        for(auto& i:nums)
        {
            int temp=i;
            temp-=min;
            int tempbu=temp/mod;
            // int tempmod=temp%mod;
            if (buksmall[tempbu]==-1)
            {
                buksmall[tempbu]=i;
                bukbig[tempbu]=i;
            }
            else
            {
                if (i>bukbig[tempbu])
                {
                    bukbig[tempbu]=i;
                }
                else if(i<buksmall[tempbu])
                {
                    buksmall[tempbu]=i;
                }
            }
        }
        int result=0;
        int small=bukbig[0];
        for (int i=1;i<l;i++)
        {
            if (bukbig[i]==-1)
            {
                continue;
            }
            result=maxOne(result,buksmall[i]-small);
            small=bukbig[i];
        }
        return result;
    }
    int abs(int i)
    {
        if (i<0)
        {
            return -1*i;
        }
        return i;
    }
    int maxOne(int i,int j)
    {
        if (i<j)
        {
            return j;
        }
        return i;
    }
};
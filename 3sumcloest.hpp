// three sum cloest
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int abs(int i,int j)
    {
        if (i<j)
        {
            return j-i;
        }
        return i-j;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int i,j,k;
        int sum;
        int cs=nums[0]+nums[1]+nums[2];
        int csabs=abs(cs,target);
        for (i=0;i<size-2;)//后面需有两个元素
        {
            j=i+1;//i后面那一个元素
            k=size-1;//最后一个元素
            while (j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                int tn;
                tn=abs(sum,target);
                if (tn<csabs)
                {
                    cs=sum;
                    csabs=tn;
                }
                if (sum==target)
                {
                    return target;
                }
                else if (sum<target)
                {
                    j++;
                }
                else 
                {
                    k--;
                }
            }
            i++;
            while(i<size-2&&nums[i]==nums[i-1])//找到下一个不同的元素
            {
                i++;
            }
        }
        return cs;
    }
    
};
// three sum
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
    //先排序3个指针，指针a遍历到没一个与前继不同的元素，然后b（a后面），c（数组后面）指针夹
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int i,j,k;
        int sum;
        for (i=0;i<size-2;)//后面需有两个元素
        {
            j=i+1;//i后面那一个元素
            k=size-1;//最后一个元素
            while (j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if (sum==0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    results.push_back(temp);
                    j++;
                    while(nums[j-1]==nums[j]&&j<k)
                    {
                        j++;
                    }
                    if(j==k)
                    {
                        break;
                    }
                }
                else if (sum<0)
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
        return results;
    }
};
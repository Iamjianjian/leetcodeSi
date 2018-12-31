#include <vector>
using namespace std;;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        while(nums[hi]==nums[lo]&&hi!=lo)
        {
            hi--;
        }
        if (hi==lo)
        {
            return nums[0];
        }
        if (nums[hi]>nums[lo])
        {
            return nums[lo];
        }

        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if (nums[mid]<nums[hi])
            {
                hi=mid;//smaller than hi 
            }
            else if (nums[mid]>nums[hi])
            {
                lo=mid+1;//bigger than hi
            }
            else
            {
                hi--;//equal hi
            }

        }
        return nums[lo];
    }
};
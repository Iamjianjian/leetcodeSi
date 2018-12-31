#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1)
        {
            return 0;
        }
        if (nums.size()==2)
        {
            int a,b;
            a=nums[0];
            b=nums[1];
            return (a<b)?1:0;
        }
        if (nums[0]>nums[1])
        {
            return 0;
        }
        int l=nums.size();
        if (nums[l-1]>nums[l-2])
        {
            return l-1;
        }
        int lo=0,hi=l-1;
        while (lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if (nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1])//peak element
            {
                return mid;
            }
            else if (nums[mid-1]<nums[mid]&&nums[mid]<nums[mid+1])//ascending order
            {
                lo=mid+1;
            }
            else//descending order
            {
                hi=mid;
            }
        }
        return lo;
    }
};
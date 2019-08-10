// https://leetcode.com/problems/search-in-rotated-sorted-array/
int search(int* nums, int numsSize, int target) {
    int l=0,h=numsSize-1;
    int mid;
    while (l<h)
    {   
        mid=l+(h-l)/2;
        if(nums[mid]>nums[h])
        {
            l=mid+1;
        }
        else
        {
            h=mid;
        }
    }
    int rot=l;
    l=0;
    h=numsSize-1;
    int rm;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        rm=(mid+rot)%numsSize;
        if(nums[rm]==target)
        {
            return rm;
        }
        else if(nums[rm]<target)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return -1;
}
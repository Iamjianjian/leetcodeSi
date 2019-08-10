/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int *results;
    results=(int*)calloc(2,sizeof(int));
    int l=0,h=numsSize-1;
    int mid;
    int local=-1;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if (nums[mid]==target)
        {
            local=mid;
            break;
        }
        else if  (nums[mid]<target)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
        
    }
    if(local==-1)
    {
        results[0]=-1;
        results[1]=-1;
        return results;
    }
    if(nums[0]==target)
    {
        results[0]=0;
    }
    else
    {
        results[0]=findIndex(nums,0,local,target);
    }
    if(nums[numsSize-1]==target)
    {
        results[1]=numsSize-1;
    }
    else
    {
        results[1]=findIndex(nums,numsSize-1,local,target);
    }
    return results;
}

int findIndex(int *nums,int side,int ts,int target)
{
    int mid;
    int flag=(side<ts)?1:-1;
    while(true)
    {
        mid=(ts+side)/2;
        if(nums[mid]==target)
        {
            ts=mid;
            if(flag==1)
            {
                if(nums[ts-1]!=target)
                {
                    return ts;
                }
            }
            else
            {
                if(nums[ts+1]!=target)
                {
                    return ts;
                }
            }
        }
        else
        {
            side=mid+flag;
            if(nums[side]==target)
            {
                return side;
            }
        }
    }
}
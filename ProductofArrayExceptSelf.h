/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int l[numsSize];
    int r[numsSize];
    *returnSize=numsSize;
    l[0]=1;
    r[numsSize-1]=1;
    int i;
    int *res=(int*)calloc(numsSize,sizeof(int));
    for (i=1;i<numsSize;i++)
    {
        l[i]=l[i-1]*nums[i-1];
        r[numsSize-1-i]=r[numsSize-i]*nums[numsSize-i];
    }
    for (int i=0;i<numsSize;i++)
    {
        res[i]=l[i]*r[i];
    }
    return res;
}
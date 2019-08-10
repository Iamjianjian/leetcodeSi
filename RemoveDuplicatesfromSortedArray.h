int removeDuplicates(int* nums, int numsSize) {
    if(numsSize<=1)
    {
        return numsSize;
    }
    int i=0,j=1;
    for (;j<numsSize;j++)
    {
        if(nums[j]==nums[i])
        {
            continue;
        }
        nums[++i]=nums[j];
    }
    return ++i;
}
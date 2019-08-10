int jump(int* nums, int numsSize) {
    if(numsSize==1)
    {
        return 0;
    }
    int lastfar=0;
    int farthest=nums[0];
    int i;
    int res=0;
    int mark;
    for (i=0;i<numsSize;i++)//each position farthest
    {
        nums[i]=i+nums[i];
    }
    while(1)
    {
        if(lastfar>=numsSize-1)
        {
            return res;
        }
        res++;
        mark=farthest;
        for (i=lastfar+1;i<=farthest&&i<numsSize;i++)
        {
            if(mark<nums[i])
            {
                mark=nums[i];
            }
        }
        lastfar=farthest;
        farthest=mark;
    }
}
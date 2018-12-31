#include<stdio.h>
int maxArea(int* height, int heightSize) {
    int i=0;
    int j=heightSize-1;
    int max=0;
    int l;
    int temp;
    while (i<j)   
    {
        l=(height[i]<height[j])?height[i]:height[j];
        max=(max<((j-i)*l))?(j-i)*l:max;
        if (height[i]<height[j])
        {
            temp=i;
            while (i<j&&height[temp]>=height[i])
            {
                i++;
            }
        }
        else
        {
            temp=j;
            while(i<j&&height[temp]>=height[j])
            {
                j--;
            }
        }
    }
    return max;
}
int main()
{
    int h[]={1,1};
    printf("%d",maxArea(h,2));
}

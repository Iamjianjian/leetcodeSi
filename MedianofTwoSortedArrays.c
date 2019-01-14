// 两数组每次去除的元素个数相等，每次确保去除不超过一半
// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<stdio.h>
double findMedianSortedArrays(int*,int,int*,int);
int main(int argc, char const *argv[])
{
    int a[]={2,3};
    int b[]={1,4,5,6};
    double c=findMedianSortedArrays(a,2,b,4);
    printf("%f",c);
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //s1短数组 s2长数组
    int s1=(nums1Size<nums2Size)?nums1Size:nums2Size;
    int s2=(nums1Size<nums2Size)?nums2Size:nums1Size;
    int *p1=(nums1Size<nums2Size)?nums1:nums2;
    int *p2=(nums1Size<nums2Size)?nums2:nums1;
    int t1;
    int t2;
    double temp;
    if(s1==0)
    {
        if (s2%2==0)
        {
            temp=(p2[s2/2]+p2[s2/2-1]);
            return temp/2;
        }
        return p2[s2/2];
    }
    while (1)
    {
        t1=(s1-1)/2;
        t2=(s2-1)/2;
        //s1<=2  短的数组只有1 ，2个元素了直接处理
        if (s1<=2)
        {
            if (s1==1)
            {
                if (s2%2==0)//p1 1个元素,p2 偶数个
                {
                    if (s2==2)//p2 2个元素 p1一个元素
                    {
                        if (p2[0]>p1[0])
                        {
                            return p2[0];
                        }
                        else if (p1[0]>=p2[1])
                        {
                            return p2[1];
                        }
                        return p1[0];
                    }
                    if(p2[t2+1]<=p1[0])//在中值后面后继后面，返回后继
                    {
                        return p2[t2+1];
                    }
                    else if (p1[0]<=p2[t2-1])//在前继前面,返回中值
                    {
                        return p2[t2];
                    }
                    else
                    {
                        return (p2[t2]>p1[0])?p2[t2]:p1[0];
                    }
                
                }
                else//p1 1个元素,p2 奇数个
                {
                    if (s2==1)//都是一个元素
                    {
                        
                        temp= (p1[0]+p2[0]);
                        return temp/2;
                    }
                    else
                    {
                        if(p1[0]<p2[t2-1])//小于前继返回前继与中间值的均值
                        {
                            temp=(p2[t2-1]+p2[t2]);
                            return temp/2;
                        }
                        else if (p1[0]>p2[t2+1])//大于后继
                        {

                            temp=(p2[t2]+p2[t2+1]);
                            return temp/2;
                        }
                        else
                        {
                            temp= (p2[t2]+p1[0]);
                            return temp/2;

                        }
                    }
                }
            }
            else//p1 2个元素
            {
                if (s2==2)//4个数的和减去最大最小值
                {
                    temp=p1[0]+p1[1]+p2[0]+p2[1];
                    temp-=(p1[1]<p2[1])?p2[1]:p1[1];
                    temp-=(p1[0]<p2[0])?p1[0]:p2[0];
                    return temp/2;
                }
                //p2最少4个元素
                if (s2%2==0)
                {
                    if (p1[0]<p2[t2-1])//p1[0]在前继前面 p1[1]的三种情况在中间前 后 内
                    {
                        if (p1[1]<p2[t2-1])
                        {
                            temp= (p2[t2-1]+p2[t2]);
                            return temp/2;
                        }
                        else if (p1[1]>p2[t2+2])
                        {
                            temp=(p2[t2+1]+p2[t2]);
                            return temp/2;
                        }
                        else//p1[1]在中间
                        {
                            if (p2[t2+1]>p1[1])
                            {
                                temp=(p1[1]+p2[t2]);
                                return temp/2;

                            }
                            else
                            {
                                temp= (p2[t2+1]+p2[t2]);
                                return temp/2;

                            }
                        }
                    }
                    else if (p1[0]>p2[t2+2])//都在后面
                    {
                        temp=(p2[t2+1]+p2[t2+2]);
                        return temp/2;
                    }
                    else//p1[0]在中间两个中值那里
                    {
                        if (p1[1]>p2[t2+1])//但p1[1]不在中间
                        {
                            temp=p2[t2+1];
                            temp+=(p1[0]<p2[t2])?p2[t2]:p1[0];
                            return temp/2;
                        }
                        else//p1的两个元素和p2的元素都在中间
                        {
                            temp=p1[0]+p1[1]+p2[t2+1]+p2[t2];
                            temp-=(p1[1]<p2[t2+1])?p2[t2+1]:p1[1];
                            temp-=(p1[0]<p2[t2])?p1[0]:p2[t2];
                            return temp/2;
                        }
                    }
                }
                else//p2奇数个元素，最少5个元素
                {
                    if(p1[1]<p2[t2-1])//第二个小于中间的前继
                    {
                        return p2[t2-1];
                    }
                    else if (p1[0]>p2[t2+1])//第一个大于中间后继
                    {
                        return p2[t2+1];
                    }
                    else
                    {
                        if (p1[0]<p2[t2-1])//p1[0]小于中继前,除了上面的哪一种还有两种情况
                        {
                            if(p1[1]>p2[t2+1])
                            {
                                return p2[t2];
                            }
                            else
                            {
                                return (p2[t2]<p1[1])?p2[t2]:p1[1];
                            }
                        }
                        else//p1[0]在中间
                        {
                            if (p1[1]>p2[t2+1])
                            {
                                return (p1[0]>p2[t2])?p1[0]:p2[t2];
                            }
                            else
                            {
                                temp=p1[0]+p2[t2]+p1[1];
                                temp-=(p1[0]<p2[t2])?p1[0]:p2[t2];
                                temp-=(p1[1]>p2[t2])?p1[1]:p2[t2];
                                return temp;
                            }
                        }
                    }
                }

            }
        }
        if (p1[t1]<p2[t2])//第t1个与第t2个比较
        {
            p1=t1+p1;//去掉前t1个,不可以去掉超过一半
            s1-=t1;
            s2-=t1;//p2去掉后面t1个
        }
        else//相反去掉p2的前t1-1个，p1的后t1-1个
        {
            p2+=t1;
            s2-=t1;
            s1-=t1;
        }
    }
}
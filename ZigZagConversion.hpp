// https://leetcode.com/problems/zigzag-conversion/
#include<string.h>
#include<stdio.h>
char* convert(char* s, int numRows) {
    int l=strlen(s);
    if(l==0||l<=numRows||numRows<=1)
    {
        return s;
    }
    char temp[l];
    int t=0;
    int i,j;
    for(i=0;i<numRows;i++)
    {
        for (j=i;j<l;j+=numRows*2-2)
        {
            printf("%d",t);
            temp[t++]=s[j];
            if (i!=0&&i!=numRows-1&&(j+numRows*2-2-2*i)<l)
            {
                temp[t++]=s[j+numRows*2-2-2*i];
            }
        }
    }
    for(int i=0;i<l;i++)
    {
        s[i]=temp[i];
    }
    return s;
}
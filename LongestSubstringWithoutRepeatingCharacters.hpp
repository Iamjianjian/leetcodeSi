// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//很简单,数组记录出现过的字母的index，i,j前后走，j遇到的字母有记录时，i逐个删除记录，记下最长长度
// 这个做法的正确性是很容易得到证明的，假设最长的是......
#include <string>
using namespace std;
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        int i,j,l,temp;
        l=s.length();
        int result=0;
        // -1表示在目前的i到j中没出现过该字母
        int indexs[128];
        for (int t=0;t<128;t++)
        {
            indexs[t]=-1;
        }
        indexs[s[0]]=0;
        i=0;
        for (j=1;j<l;j++)
        {
            if (indexs[s[j]]!=-1)//有重复字母
            {
                result=(result<(j-i))?(j-i):result;
                temp=indexs[s[j]];//拿到重复字母的index
                while(i<=temp)
                {
                    indexs[s[i]]=-1;
                    i++;
                }
                indexs[s[j]]=j;
            }
            else
            {
                indexs[s[j]]=j;
            }
        }
        result=(result<(j-i))?(j-i):result;
        return result;
    }
};
#include <string>
#include<algorithm>
using namespace std;
// substr index length
class Solution {
public:
// 记录前面的i个字符在原字符串中是否有可能为连在一起的，即前i个s1的字符 s2都有
// 第一次的循环情况表示s1的子串没有交换，第二次把字符串s2反转再作一次表示s1的子串交换了
    bool isScramble(string s1, string s2) {// first 代表是否为第一次分，第一次分不可以全部分为一组
        return isScrambleHelper(s1,s2,false);
    }
    bool isScrambleHelper(string s1,string s2,bool rev)
    {
// 0 1 的长度直接处理
        int l=s1.size();
        if (l==1)
        {
            return s1[0]==s2[0];
        }
        else if (l==0)
        {
            return true;
        }

        int count=0;
        int hash[26];
        for (auto &num:hash)
        {
            num=0;
        }
        for (int i=1;i<l;i++)
        {
            int temp=s1[i-1]-'a';
            hash[temp]++;
            if (hash[temp]==0)
            {
                count--;
            }
            if (hash[temp]==1)
            {
                count++;
            }
            temp=s2[i-1]-'a';
            hash[temp]--;
            if (hash[temp]==0)
            {
                count--;
            }
            if (hash[temp]==-1)
            {
                count++;
            }
            if (count==0)
            {
                string sub1=s1.substr(0,i);
                string sub2=s2.substr(0,i);
                if (!isScrambleHelper(sub1,sub2,false))
                {
                    continue;
                }
                sub1=s1.substr(i,l-i);
                sub2=s2.substr(i,l-i);
                if (!isScrambleHelper(sub1,sub2,false))
                {
                    continue;
                }
                return true;
            }
        }
        if (!rev)
        {
            reverse(s2.begin(),s2.end());
            return isScrambleHelper(s1,s2,true);
        }

        return false;
    }
};

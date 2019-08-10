
// https://leetcode.com/problems/valid-parentheses/
#include<string.h>
bool isValid(char* s) {
    int l=strlen(s);
    if (l==0)
    {
        return true;
    }
    if (l%2)//odd must false
    {
        return false;
    }
    int sl=l/2;
    char stack[sl];
    int i=-1;
    for (int j=0;s[j]!='\0';j++)
    {
        if (s[j]=='['||s[j]=='('||s[j]=='{')
        {
            if(i==sl-1)//over stack must unfit
            {
                return false;
            }
            stack[++i]=s[j];
        }
        else
        {
            if(i==-1)
            {
                return false;
            }
            switch (s[j])
            {
                case ']':
                    if(stack[i--]!='[')
                    {
                        return false;
                    }
                    break;
            
                case '}':
                    if(stack[i--]!='{')
                    {
                        return false;
                    }
                    break;
            
                case ')':
                    if(stack[i--]!='(')
                    {
                        return false;
                    }
                    
                    break;
            
                default:
                    break;
            }
        }
    }
    if (i==-1)
    {
        return true;
    }
    return false;
}
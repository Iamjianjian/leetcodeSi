// https://leetcode.com/problems/dungeon-game/
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size()==0||dungeon[0].size()==0)
        {
            return 0;
        }
        int row=dungeon.size();
        int col=dungeon[0].size();
        int results[row][col];
        if (dungeon[row-1][col-1]>=0)
        {
            results[row-1][col-1]=0;
        }
        else
        {
            results[row-1][col-1]=-1*dungeon[row-1][col-1];
        }
        for (int i=row-1;i>=0;i--)
        {
            for (int j=col-1;j>=0;j--)
            {
                int temp1,temp2;
                bool b1=false,b2=false;
                if (i!=row-1)
                {
                    temp1=results[i+1][j]-dungeon[i][j];
                    b1=true;
                }
                if (j!=col-1)
                {
                    temp2=results[i][j+1]-dungeon[i][j];                    
                    b2=true;
                }
                if (b2&&b1)
                {
                    results[i][j]=min(temp1,temp2);
                }
                else if (b1)
                {
                    results[i][j]=temp1;
                }
                else if (b2)
                {
                    results[i][j]=temp2;
                }
                if (results[i][j]<0)
                {
                    results[i][j]=0;
                }
            }
        }
        return results[0][0]+1;
    }
    int min(int i,int j)
    {
        if (i<j)
        {
            return i;
        }
        return j;
    }
};
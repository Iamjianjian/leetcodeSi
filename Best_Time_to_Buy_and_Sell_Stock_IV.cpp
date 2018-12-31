#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    // dp 解决 i个数字 k次购买 ：要么 在i卖出 要么为 i-1 k
    int maxProfit(int k, vector<int>& prices) {
        //rmove duplicate
        auto it=unique(prices.begin(),prices.end());
        prices.erase(it,prices.end());
        int size=prices.size();
        int profit[size][k+1];
        for (int i=0;i<size;i++)//zero time buy and sell
        {
            profit[i][0]=0;
        }
        int maxpro;
        for(int i=1;i<k+1;i++)
        {
            profit[0][i]=0;
            maxpro=-1*prices[0];//购买 并且前面0个的利润为0
            //觉得此处的前k*2天的结果必然是 i-1 次交易的值
            for (int j=1;j<size;j++)
            {
                int temp1,temp2,temp;
                temp1=maxpro+prices[j];//卖出
                temp2=profit[j-1][i];//不卖出,仅仅在前面j-1个价格中交易i次
                if(temp1<temp2)
                {
                    profit[j][i]=temp2;
                }
                else
                {
                    profit[j][i]=temp1;
                }
                temp=profit[j-1][i-1]+prices[j];//记录下一次卖出的最大利润
                if (maxpro<temp)
                {
                    maxpro=temp;
                }
            }
        }
        return profit[size-1][k];
    }
    int quickSolve(vector<int>&prices)
    {

    }
};


int main()
{
    vector<int>a;
    a.push_back(1);
    cout <<a[0];
}
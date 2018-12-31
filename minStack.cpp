#include <vector>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> data;
    vector<int>minNums;
    MinStack() {
        ;
    }
    
    void push(int x) {
        data.push_back(x);
        if (minNums.size()==0)
        {
            minNums.push_back(x);
            return;
        }
        if (x<minNums[minNums.size()-1])
        {
            minNums.push_back(x);
        }
        else
        {
            minNums.push_back(minNums[minNums.size()-1]);
        }
    }
    
    void pop() {
        data.pop_back();
        minNums.pop_back();
    }
    
    int top() {
        return data[data.size()-1];
    }
    
    int getMin() {
        return minNums[minNums.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
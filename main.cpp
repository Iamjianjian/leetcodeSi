#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "3sum.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int aa[]={-1,0,1,2,-1,-4};
    vector<int>a(7);
    copy(aa,aa+6,a.begin());
    Solution c;
    c.threeSum(a);
    return 0;
}

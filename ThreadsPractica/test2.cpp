#include <iostream>
using namespace std;

template<int n>
struct Fact
{
    enum{RET=n*Fact<n-1>::RET};
};

template<>
struct Fact<0>
{
    enum{RET=1};
};

int main()
{

    Fact<5>::RET;
    int i = 3;
    Fact<i>::RET;
    return 0;
}
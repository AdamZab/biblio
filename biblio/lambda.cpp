#include <algorithm>
#include <iostream>

using namespace std;

int main()
{

    int k=3, n=4;
    auto f1=[&](){return k+n;};

    cout << f1() <<endl;

   
}

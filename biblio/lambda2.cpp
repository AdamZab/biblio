#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int v[10]{1,2,3,4,4,3,7,8,9,10};
    for_each(v, v+10, [](int x){cout << x << " ";});
    //cout << count_if(v, v+10, [](int x){return x==3;}) << endl;
    
  
}

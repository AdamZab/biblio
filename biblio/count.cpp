#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int array[5]{1,2,5,3,4};
    auto x=count(array,array+5,3);
    cout << x <<endl;
    return 0;    
}    

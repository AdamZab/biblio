// Program [n] [typ]
// gdzie n to ilosc elementow do posortowania
//gdzie typ to wybor czy babelkowe czy sort

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

int main (int argc, char ** argv)
{
    
    int n = atoi(argv[1]);
    
    
    vector <int> x;
   
    int tmp, ii, jj;
    
    
    x.resize(n);
    
    for(auto &xx:x){
        xx=rand()%100;
    }
    
    for_each(x.begin(), x.end(),[] (auto &x){x=rand()%100;});
    
    sort(x.begin(), x.end());

    cout << x << endl;
    

    return 0;
}


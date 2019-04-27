#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

//bool cmp(const  &a, const  &b);



int main()
{
    array<string,8> lista{"mak", "Mar", "qwe", "Tyu", "Mot", "gfs", "gdu", "poi"};
    int a;
    string b,c;
    
    
    
   /* cout << "at:" << endl;
    
    for (int i=0; i<8; ++i)
        cout << lista.at(i) << endl;
    
    cout << "[]:" << endl;

    for (int i=0; i<8; ++i)
        cout << lista[i] << endl;*/
    
    cout << "1 dla rosnacej, 2 dla malejacej" << endl;
    
    cin >> a;
    

    
     
    if (a==1)
    {
    
        cout << "rosnaca:" << endl;
        sort(lista.begin(), lista.end());
        
    }
    
    if (a==2)
    {
        cout << "malejaca:" << endl;
        sort(lista.begin(), lista.end(),greater<>());
        
    }
    
        
    for (int i=0; i<8; ++i)
        cout << lista.at(i) << endl;
    
    cout << "stary element" << endl;
    
    cin >> b;
    
    cout << "nowy element" << endl;
    cin >> c;

    for_each(lista.begin(), lista.end(), []);
    
return 0;    
}

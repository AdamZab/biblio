#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;





int main()
{
    vector<string> lista{"alfa", "beta", "gamma", "delta"};
    
    
    
    
   cout << "2. wypisanie:" << endl;
    
    for (int i=0; i<4; ++i)
    {
        auto f1=[&](){return lista.at(i);};
        cout << f1() <<endl;
    }
 
     
    
    cout << endl << "3. malejaca:" << endl;
    sort(lista.begin(), lista.end(), greater<>());
       
    for (int i=0; i<4; ++i)
        cout << lista.at(i) << endl;
        
     
 
        
    cout << endl << "4. rosnaca:" << endl;
    sort(lista.begin(), lista.end());
        
        
    for (int i=0; i<4; ++i)
        cout << lista.at(i) << endl;
    
    cout << endl << "5. dodanie *:" << endl;
    
    for (int i=0; i<4; ++i)
        lista.at(i) = lista.at(i) + "*";
    
    for (int i=0; i<4; ++i)
    {
        auto f1=[&](){return lista.at(i);};
        cout << f1() <<endl;
    }
    
    /*cout << endl << "6. dodanie iczby:" << endl;
    
    for (int i=0; i<4; ++i)
        lista.at(i) = lista.at(i) + ;
    
    for (int i=0; i<4; ++i)
    {
        auto f1=[&](){return lista.at(i);};
        cout << f1() <<endl;
    }*/
    
    cout << endl << "7. zamiana 1 elementu:" << endl;
    
    lista.at(0) = "zero";
    
    for (int i=0; i<4; ++i)
    {
        auto f1=[&](){return lista.at(i);};
        cout << f1() <<endl;
    }
    
    cout << endl << "8. usuniecie elementow:" << endl;
    
    lista.erase(lista.begin() + 1);
    lista.erase(lista.end() - 1);
    

    for (int i=0; i<2; ++i)
    {
        auto f1=[&](){return lista.at(i);};
        cout << f1() <<endl;
    }

    
        
return 0;    
}

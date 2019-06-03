#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    map<string, int> student;
    
    
    ifstream plik;
    plik.open("oceny");
    if(!plik.good())
         return false;
   
    while( true )
    {
        string imie;
        int ocena;
        plik >> imie >> ocena;
        if(!plik.fail()){
            student.emplace(imie, ocena);
            for (const auto &pair:student)
                cout <<pair.first << ":"<<pair.second << "\n";
        }
        else
             break;
    }
}
    

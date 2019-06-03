#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

struct Pet
{
string name;
Pet(const string& s) : name(s){}
//Pet() = default;
//Pet() {};
};



int main()
{



 map<int, string> pets;

 
pets.emplace(0, "Pies Azor");
pets.emplace(1, "Kot miauczek");
for (const auto &pair:pets){
        cout <<pair.first << ":"<<pair.second << "\n";
}
pets.emplace(2, "Pies Azor");
pets.emplace(3, "Pies Azor");
for (const auto &pair:pets){
        cout <<pair.first << ":"<<pair.second << "\n";
}

string s = "Pies Azor";
//pets.erase(pair.second(s)); jeszcze niedziala;



}

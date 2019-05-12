#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Person {
public:
    string name;
    string surname;
    int age;
    
public:
    Person(string _name, string _surname, int _age);
};

int main()
{
    srand(time(nullptr));
    vector<string> name{"Adam", "Tomasz", "Marcin", "Jan", "Milosz", "Mateusz", "Adrian", "Marek", "Michal", "Darek"};
    
    vector<string> surname{"Kowal", "Tkacz", "Nowak", "Malinowski", "Jankowski", "Kowalski", "Mickiewicz", "Slowacki", "Krasinski", "Psikuta"};

    Person jeden;
   jeden.name=name.at(rand()%10);
}

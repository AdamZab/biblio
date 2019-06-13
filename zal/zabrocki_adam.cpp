#include <map>
#include <unordered_map>
#include "person.h"
#include "timer.h"
#include <iostream>
#include <memory>


template <class Map>
void prepare_people_map(Map & map, const long elems_no, int operationRepeater)
{
    for (int jj=0; jj<operationRepeater; ++jj){
        for (int ii=0; ii<elems_no; ++ii) {
            person::Person p(person::get_random_person());
            map.emplace(ii , p);
        }
    }
}

template <class Unordered_map>
void prepare_people_unordered_map(Unordered_map & unordered_map, const long elems_no, int operationRepeater)
{
    for (int jj=0; jj<operationRepeater; ++jj){
        for (int ii=0; ii<elems_no; ++ii) {
            person::Person p(person::get_random_person());
            unordered_map.emplace(ii , p);
        }
    }
}


template <class Map>
void add_person_map(Map & map, const long elems_no, char ifRandom, int operationRepeater)
{
    if(ifRandom=='Y' || ifRandom=='y'){
        for (int jj=0; jj<operationRepeater; ++jj){
            person::Person p(person::get_random_person());
            map.emplace(elems_no+jj, p);
        }
    }
    else {
        std::cout << "dodawanie do map:" << std::endl;
        person::Person p(person::get_specific_person());
        map.emplace(elems_no, p);
    }
}

template <class Unordered_map>
void add_person_unoreded_map(Unordered_map & unordered_map, const long elems_no, char ifRandom, int operationRepeater)
{
    if(ifRandom=='Y' || ifRandom=='y'){
        for (int jj=0; jj<operationRepeater; ++jj){
            person::Person p(person::get_random_person());
            unordered_map.emplace(elems_no+jj, p);
        }
    }
    else {
        std::cout << "dodawanie do unoredered_map:" << std::endl;
        person::Person p(person::get_specific_person());
        unordered_map.emplace(elems_no, p);
    }
}


template <class Map>
void find_person_map(Map & map, const long elems_no, long key, char ifRandom, int operationRepeater)
{
    for (int jj=0; jj<operationRepeater; ++jj){
        if(ifRandom=='Y' || ifRandom=='y')
            key = std::rand()%elems_no-1;
        std::map<long ,person::Person>::iterator it;
        it = map.find(key);
        if(it == map.end()) 
            std::cout << "Nie ma takiego klucza" << std::endl ; 
        else
            std::cout << "Znaleziono (map):" << std::endl << it->first << ": " << it->second << std::endl ; 
    }
}


template <class Unordered_map>
void find_person_unoreded_map(Unordered_map & unordered_map, const long elems_no, long key, char ifRandom, int operationRepeater)
{
    for (int jj=0; jj<operationRepeater; ++jj){
        if(ifRandom=='Y' || ifRandom=='y')
            key = std::rand()%elems_no-1;
        std::unordered_map<long ,person::Person>::iterator it;
        it = unordered_map.find(key);
        if(it == unordered_map.end()) 
            std::cout << "Nie ma takiego klucza" ; 
        else
            std::cout << "Znaleziono (unordered_map):" << std::endl << it->first << ": " << it->second << std::endl ; 
    }
}

template <class Map>
void erase_person_map(Map & map, const long elems_no, long key, char ifRandom, int operationRepeater)
{
    for (int jj=0; jj<operationRepeater; ++jj){
        if(ifRandom=='Y' || ifRandom=='y')
            key = std::rand()%elems_no-1;
        std::map<long ,person::Person>::iterator it;
        it = map.find(key);
        if(it == map.end()) 
            std::cout << "Nie ma takiego klucza" ; 
        else
            map.erase (it); 
    }
}


template <class Unordered_map>
void erase_person_unoreded_map(Unordered_map & unordered_map, const long elems_no, long key, char ifRandom, int operationRepeater)
{
    for (int jj=0; jj<operationRepeater; ++jj){
        if(ifRandom=='Y' || ifRandom=='y')
            key = std::rand()%elems_no;
        std::unordered_map<long ,person::Person>::iterator it;
        it = unordered_map.find(key);
        if(it == unordered_map.end()) 
            std::cout << "Nie ma takiego klucza" ; 
        else
            unordered_map.erase (it); 
    }
}


template <class Map>
void print_map(Map & map, const long elems_no)
{
    std::cout << std::endl << "map:" << std::endl;
    for(const auto &pair : map)
            std::cout << pair.first << ": " << pair.second << std::endl;
}

template <class Unordered_map>
void print_unordered_map(Unordered_map & unordered_map, const long elems_no)
{
    std::cout << std::endl << "unordered_map:" << std::endl;
    for(const auto &pair : unordered_map)
            std::cout << pair.first << ": " << pair.second << std::endl;
}


int main(int argc, char ** argv)
{
        long elems_no=0, key;
        int menuSwitch, operationRepeater;
        char ifRandom;
        std::map<long ,person::Person> m1;
        std::unordered_map<long,person::Person> m2;
        do
        {
            std::cout << std::endl << "1 - wstawienie N elementów do pustej mapy" << std::endl;
            std::cout << "2 - wstawianie elementu do mapy z N elementami" << std::endl;
            std::cout << "3 - szukanie elementów w N-elementowej mapie" << std::endl;
            std::cout << "4 - usuwanie określonego elementu z N-elementowej mapy" << std::endl;
            std::cout << "5 - drukowanie map" << std::endl;
            std::cout << "0 - wyjście" << std::endl;
            std::cin >> menuSwitch;
            switch (menuSwitch)
            {
                case 1:
                {
                    std::cout << std::endl << "podaj ilość elementów: ";
                    std::cin >> elems_no;
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    prepare_people_map(m1,elems_no,operationRepeater);
                    prepare_people_unordered_map(m2,elems_no,operationRepeater);
                    break;
                }
                    
                case 2:
                {
                    std::cout << std::endl << "Dodać losową osobę?(Y?)";
                    std::cin >> ifRandom;
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    add_person_map(m1,elems_no,ifRandom, operationRepeater);
                    add_person_unoreded_map(m2,elems_no,ifRandom, operationRepeater);
                    break;
                }
                
                case 3:
                {
                    std::cout << std::endl << "Szukać losową osobę?(Y?)";
                    std::cin >> ifRandom;
                    if(ifRandom!='Y' && ifRandom!='y'){
                        std::cout << std::endl << "podaj klucz osoby: " << std::endl;
                        std::cin >> key;
                    }
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    find_person_map(m1,elems_no,key, ifRandom, operationRepeater);
                    find_person_unoreded_map(m2,elems_no,key, ifRandom, operationRepeater);
                    break;
                }
                
                case 4:
                {
                    std::cout << std::endl << "Szukać losową osobę?(Y?)";
                    std::cin >> ifRandom;
                    if(ifRandom!='Y' && ifRandom!='y'){
                        std::cout << std::endl << "podaj klucz osoby: " << std::endl;
                        std::cin >> key;
                    }
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    erase_person_map(m1,elems_no,key, ifRandom, operationRepeater);
                    erase_person_unoreded_map(m2,elems_no,key, ifRandom, operationRepeater);
                    break;
                }
        
        
                case 5:
                {
                    print_map(m1,elems_no);
                    print_unordered_map(m2,elems_no);
                    break;
                }
                
                case 0:
                {
                    break;
                }
                
                default:
                {
                     std::cout << std::endl << "Niepoprawny wybór, wybierz ponownie";
                     break;
                }
            }
                    
        }while (menuSwitch!=0);
        
    return 0;
}

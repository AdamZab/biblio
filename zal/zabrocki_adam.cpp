#include <map>
#include <unordered_map>
#include "person.h"
#include "timer.h"
#include <iostream>
#include <memory>


template <class Map>
void prepare_people_map(Map & map, const long elems_no)
{
    for (int ii=0; ii<elems_no; ++ii) {
        person::Person p(person::get_random_person());
        map.emplace(ii , p);
    }
}

template <class Unordered_map>
void prepare_people_unordered_map(Unordered_map & unordered_map, const long elems_no)
{
    for (int ii=0; ii<elems_no; ++ii) {
        person::Person p(person::get_random_person());
        unordered_map.emplace(ii , p);
    }
}


template <class Map>
void add_person_map(Map & map, const long elems_no)
{
    std::cout << "dodawanie do map:" << std::endl;
    person::Person p(person::get_specific_person());
    map.emplace(elems_no, p);
}

template <class Unordered_map>
void add_person_unoreded_map(Unordered_map & unordered_map, const long elems_no)
{
    std::cout << "dodawanie do unoredered_map:" << std::endl;
    person::Person p(person::get_specific_person());
    unordered_map.emplace(elems_no, p);
}


template <class Map>
void find_person_map(Map & map, const long elems_no, long key)
{
   
    std::map<long ,person::Person>::iterator it;
    it = map.find(key);
    if(it == map.end()) 
        std::cout << "Nie ma takiego klucza" ; 
    else
        std::cout << "Znaleziono (map):" << std::endl << it->first << ": " << it->second << std::endl ; 
}


template <class Unordered_map>
void find_person_unoreded_map(Unordered_map & unordered_map, const long elems_no, long key)
{
    std::unordered_map<long ,person::Person>::iterator it;
    it = unordered_map.find(key);
    if(it == unordered_map.end()) 
        std::cout << "Nie ma takiego klucza" ; 
    else
        std::cout << "Znaleziono (unordered_map):" << std::endl << it->first << ": " << it->second << std::endl ; 
}

template <class Map>
void erase_person_map(Map & map, const long elems_no)
{
    long key;
    std::cout << std::endl << "podaj klucz osoby (map): " << std::endl;
    std::cin >> key;
    std::map<long ,person::Person>::iterator it;
    it = map.find(key);
    if(it == map.end()) 
        std::cout << "Nie ma takiego klucza" ; 
    else
        std::cout << "Znaleziono:" << std::endl << it->first << ": " << it->second << std::endl ; 
}


template <class Unordered_map>
void erase_person_unoreded_map(Unordered_map & unordered_map, const long elems_no, long key)
{
    std::unordered_map<long ,person::Person>::iterator it;
    it = unordered_map.find(key);
    if(it == unordered_map.end()) 
        std::cout << "Nie ma takiego klucza" ; 
    else
        std::cout << "Znaleziono (unordered_map):" << std::endl << it->first << ": " << it->second << std::endl ; 
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
        long elems_no=0;
        int menuSwitch;
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
                    prepare_people_map(m1,elems_no);
                    prepare_people_unordered_map(m2,elems_no);
                    break;
                }
                    
                case 2:
                {
                    add_person_map(m1,elems_no);
                    add_person_unoreded_map(m2,elems_no);
                    break;
                }
                
                case 3:
                {
                    long key;
                    std::cout << std::endl << "podaj klucz osoby: " << std::endl;
                    std::cin >> key;
                    find_person_map(m1,elems_no,key);
                    find_person_unoreded_map(m2,elems_no,key);
                    break;
                }
                
                case 4:
                {
                    //erase_person_map(m1,elems_no);
                    //erase_person_unoreded_map(m2,elems_no);
                    break;
                }
        
        //std::vector<long long> ids;
        // wypelnic odpowiednio wektor
        //test_find_for_people(m1, ids);
        // ...
        //std::unordered_map<int,person::Person> m1;
        // powtarzamy jak wyzej
        
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

//performance_frame.cpp
//Wyświetlanie 02.1_tasks_map_multimap.cpp.

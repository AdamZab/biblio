#include <map>
#include <unordered_map>
#include "person.h"
#include "timer.h"
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <fstream>


template <class Map>
void prepare_people_map(Map & map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        for (int elemsCounter=0; elemsCounter<multiple; ++elemsCounter) {
            person::Person p(person::get_random_person());
            map.emplace(elemsCounter , p);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream ppmr;
    ppmr.open ("prepare_people_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    ppmr << multiple << "        " << average_time << std::endl;
    ppmr.close();
}

template <class Unordered_map>
void prepare_people_unordered_map(Unordered_map & unordered_map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        for (int elemsCounter=0; elemsCounter<multiple; ++elemsCounter) {
            person::Person p(person::get_random_person());
            unordered_map.emplace(elemsCounter , p);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream ppumr;
    ppumr.open ("prepare_people_unordered_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    ppumr << multiple << "        " << average_time << std::endl;
    ppumr.close();
}

template <class Map>
void prepare_people_map_without_results(Map & map, const long multiple)
{
    for (int elemsCounter=0; elemsCounter<multiple; ++elemsCounter) {
        person::Person p(person::get_random_person());
        map.emplace(elemsCounter , p);
    }

}

template <class Unordered_map>
void prepare_people_unordered_map_without_results(Unordered_map & unordered_map, const long multiple)
{
    for (int elemsCounter=0; elemsCounter<multiple; ++elemsCounter) {
        person::Person p(person::get_random_person());
        unordered_map.emplace(elemsCounter , p);
    }
}


template <class Map>
void add_person_map(Map & map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        person::Person p(person::get_random_person());
        map.emplace(multiple, p);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream apmr;
    apmr.open ("add_person_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    apmr << multiple << "        " << average_time << std::endl;
    apmr.close();
    
}

template <class Unordered_map>
void add_person_unoreded_map(Unordered_map & unordered_map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        person::Person p(person::get_random_person());
        unordered_map.emplace(multiple, p);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream apumr;
    apumr.open ("add_person_unordered_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    apumr << multiple << "        " << average_time << std::endl;
    apumr.close();
}


template <class Map>
void find_person_map(Map & map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    long key;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        key = std::rand()%multiple-1;
        std::map<long ,person::Person>::iterator it;
        it = map.find(key); 
        if(it == map.end()) 
            std::cout << "Nie ma takiego klucza" << std::endl ;
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream fpmr;
    fpmr.open ("find_person_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fpmr << multiple << "        " << average_time << std::endl;
    fpmr.close();
}


template <class Unordered_map>
void find_person_unoreded_map(Unordered_map & unordered_map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    long key;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        key = std::rand()%multiple-1;
        std::unordered_map<long ,person::Person>::iterator it;
        it = unordered_map.find(key); 
        if(it == unordered_map.end()) 
            std::cout << "Nie ma takiego klucza" << std::endl; 
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream fpumr;
    fpumr.open ("find_person_unordered_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fpumr << multiple << "        " << average_time << std::endl;
    fpumr.close();
}

template <class Map>
void erase_person_map(Map & map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    long key;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        key = std::rand()%multiple-1;
        std::map<long ,person::Person>::iterator it;
        it = map.find(key);
        if(it == map.end()) 
            std::cout << "Nie ma takiego klucza" << std::endl; 
        else 
        map.erase (it);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream epmr;
    epmr.open ("erase_person_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    epmr << multiple << "        " << average_time << std::endl;
    epmr.close();
}


template <class Unordered_map>
void erase_person_unoreded_map(Unordered_map & unordered_map, const long multiple, int operationRepeater)
{
    double average_time=0;
    std::vector<double> elapsed_time;
    long key;
    for (int repeaterCounter=0; repeaterCounter<operationRepeater; ++repeaterCounter){
        auto start = std::chrono::system_clock::now();
        key = std::rand()%multiple-1;
        std::unordered_map<long ,person::Person>::iterator it;
        it = unordered_map.find(key);
        if(it == unordered_map.end()) 
            std::cout << "Nie ma takiego klucza" << std::endl; 
        else 
        unordered_map.erase (it);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        elapsed_time.push_back(elapsed_seconds.count());
    }
    std::sort(elapsed_time.begin(), elapsed_time.end());
    if(operationRepeater > 3){
        elapsed_time.erase(elapsed_time.begin());
        elapsed_time.erase(elapsed_time.end()-1);
    }
    for (auto vectorElem = elapsed_time.begin(); vectorElem != elapsed_time.end(); ++vectorElem)
    average_time=average_time+*vectorElem;
    average_time=average_time/elapsed_time.size();
    std::fstream epumr;
    epumr.open ("erase_person_unordered_map_results.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    epumr << multiple << "        " << average_time << std::endl;
    epumr.close();
}


template <class Map>
void print_map(Map & map, const long multiple)
{
    std::cout << std::endl << "map:" << std::endl;
    for(const auto &pair : map)
            std::cout << pair.first << ": " << pair.second << std::endl;
}

template <class Unordered_map>
void print_unordered_map(Unordered_map & unordered_map, const long multiple)
{
    std::cout << std::endl << "unordered_map:" << std::endl;
    for(const auto &pair : unordered_map)
            std::cout << pair.first << ": " << pair.second << std::endl;
}


int main(int argc, char ** argv)
{
        long multiple=0, staticMultiple=0, elems_no=0;
        int menuSwitch, operationRepeater;
        std::map<long ,person::Person> m1;
        std::unordered_map<long,person::Person> m2;
        do
        {
            multiple=0;
            std::cout << std::endl << "1 - wstawienie N elementów do pustej mapy" << std::endl;
            std::cout << "2 - wstawianie elementu do mapy z N elementami" << std::endl;
            std::cout << "3 - szukanie elementów w N-elementowej mapie" << std::endl;
            std::cout << "4 - usuwanie elementu z N-elementowej mapy" << std::endl;
            std::cout << "5 - drukowanie map" << std::endl;
            std::cout << "0 - wyjście" << std::endl;
            std::cin >> menuSwitch;
            switch (menuSwitch)
            {
                case 1:
                {
                    std::ofstream ppmr;
                    ppmr.open ("prepare_people_map_results.txt");
                    ppmr << "";
                    ppmr.close();
                    std::ofstream ppumr;
                    ppumr.open ("prepare_people_unordered_map_results.txt");
                    ppumr << "";
                    ppumr.close();
                    std::cout << std::endl << "podaj ilość elementów: ";
                    std::cin >> elems_no;
                    std::cout << std::endl << "wielokrotność: ";
                    std::cin >> staticMultiple;
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    for (int multipleIterator=1; multipleIterator<=elems_no; ++multipleIterator){
                        multiple=multiple+staticMultiple;
                        prepare_people_map(m1,multiple,operationRepeater);
                        prepare_people_unordered_map(m2,multiple,operationRepeater);
                    }
                    break;
                }
                    
                case 2:
                {
                    std::ofstream apmr;
                    apmr.open ("add_person_map_results.txt");
                    apmr << "";
                    apmr.close();
                    std::ofstream apumr;
                    apumr.open ("add_person_unordered_map_results.txt");
                    apumr << "";
                    apumr.close();
                    std::cout << std::endl << "podaj ilość elementów: ";
                    std::cin >> elems_no;
                    std::cout << std::endl << "wielokrotność: ";
                    std::cin >> staticMultiple;
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    for (int multipleIterator=1; multipleIterator<=elems_no; ++multipleIterator){
                        multiple=multiple+staticMultiple;
                        prepare_people_map_without_results(m1,multiple);
                        add_person_map(m1,multiple, operationRepeater);
                        prepare_people_unordered_map_without_results(m2,multiple);
                        add_person_unoreded_map(m2,multiple, operationRepeater);
                    }
                    break;
                }
                
                case 3:
                {
                    std::ofstream fpmr;
                    fpmr.open ("find_person_map_results.txt");
                    fpmr << "";
                    fpmr.close();
                    std::ofstream fpumr;
                    fpumr.open ("find_person_unordered_map_results.txt");
                    fpumr << "";
                    fpumr.close();
                    std::cout << std::endl << "podaj ilość elementów: ";
                    std::cin >> elems_no;
                    std::cout << std::endl << "wielokrotność: ";
                    std::cin >> staticMultiple;
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    for (int multipleIterator=1; multipleIterator<=elems_no; ++multipleIterator){
                        multiple=multiple+staticMultiple;
                        prepare_people_map_without_results(m1,multiple);
                        find_person_map(m1,multiple, operationRepeater);
                        prepare_people_map_without_results(m2,multiple);
                        find_person_unoreded_map(m2,multiple, operationRepeater);
                    }
                    break;
                }
                
                case 4:
                {
                    std::ofstream epmr;
                    epmr.open ("erase_person_map_results.txt");
                    epmr << "";
                    epmr.close();
                    std::ofstream epumr;
                    epumr.open ("erase_person_unordered_map_results.txt");
                    epumr << "";
                    epumr.close();
                    std::cout << std::endl << "podaj ilość elementów: ";
                    std::cin >> elems_no;
                    std::cout << std::endl << "wielokrotność: ";
                    std::cin >> staticMultiple;
                    std::cout << std::endl << "ile razy powtórzyć operację?: ";
                    std::cin >> operationRepeater;
                    for (int multipleIterator=1; multipleIterator<=elems_no; ++multipleIterator){
                        multiple=multiple+staticMultiple;
                        prepare_people_map_without_results(m1,multiple);
                        erase_person_map(m1,multiple,operationRepeater);
                        prepare_people_map_without_results(m2,multiple);
                        erase_person_unoreded_map(m2, multiple, operationRepeater);
                    }
                    break;
                }
        
        
                case 5:
                {
                    print_map(m1,multiple);
                    print_unordered_map(m2,multiple);
                    break;
                }
                
                case 0:
                {
                    break;
                }
                
                default:
                {
                     std::cout << std::endl << "Niepoprawny wybór, wybierz ponownie" << std::endl;
                     break;
                }
            }
                    
        }while (menuSwitch!=0);
        
    return 0;
}

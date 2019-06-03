#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <ctime>
#include <unordered_map>

void printMap( const std::multimap< int , std::string >& mapToPrint ) ;

class Person {
   public:
      std::string name;
      std::string surname;
      int age;
   
      Person(std::string n, std::string s,int a): name(n), surname (s), age(a){};
   void   print()
   {
      std::cout << name << " " << surname << " age: " << age << std::endl;
   }
};

int main( int argc, char const *argv[] )
{
   std::srand(std::time(nullptr));
   std::rand();
   std::vector<std::string> imiona {"Marcin", "Agnieszka", "Maciej", "Władysław", 
                                    "Tomasz", "Damian", "Kleofas"};
   std::vector<std::string> nazwiska {"Koryto", "Drewutnia", "Denko", "Podeszwa", 
                                    "Roman", "Kopytko", "Kartofel"};
   
   std::vector<Person> Lista;
   for(int i {0}; i<20; i++)
   {
      Lista.push_back(
            Person(imiona.at(std::rand()%imiona.size()),
            nazwiska .at(std::rand()%imiona.size()),
            std::rand()%100));
   }
   for(auto& listElement : Lista)
   {
      listElement.print();
   }


std::unordered_map<int,Person> people;
for (int i=0;i<10;++i)
{
auto p=Lista.at(i);
people.emplace(p.age,p);//people.emplace(p.age,p);
}

for (const auto &pair:people){
        std::cout <<pair.first << ":"<< "\n";

}

//for(auto iter = people.begin(); iter != people.end(); ++iter)
//for (int i=0;i<10;++i)
//{
//std::cout<<people.at(i)<<"\n";

//}
//print(people);

}



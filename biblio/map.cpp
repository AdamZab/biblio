#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
   
    multimap<string, int> coding {{"alfa", 1}, {"beta", 3}};
    
    cout << "start:" << endl;
    
    for(const auto &pair : coding)
        cout << pair.first << ": " << pair.second << endl;
    
    //coding["gamma"] = 3;
    //coding["beta"] = 2;
    
    coding.emplace("delta", 4);
    
    //coding["theta"]+=1;
    //coding["theta"]+=1;
    
    cout << "stop:\n";
    
    for(const auto &pair : coding)
        cout << pair.first << ": " << pair.second << endl;
    
}
        

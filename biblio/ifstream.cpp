#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(int, char **)
{
    ifstream file;
    file.open ("ifstream.cpp");
    string word;
    while (file >> word)
        cout << word << endl;
}
    

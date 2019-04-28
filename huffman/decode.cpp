#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>


using namespace std;

void ReadCode(string fileSign, string fileCode, string text)
{
    string codedText;
    ifstream fileText; 
    fileText.open(text.c_str());
    fileText >> codedText;
    unsigned int i=1;
    cout << fileSign << " " << fileCode << endl;
    
    for(i; i < text.length(); ++i)
    {
        string tempCodedText = codedText.substr(0,i);
        cout << tempCodedText << endl;
        if(tempCodedText == fileCode)
        {
            cout << fileSign;
            codedText.erase(0,i);
            break;
        }
        sleep(1);
    }
       
}

bool ReadFiles(string decode, string text)
{
    unsigned int i;
    ifstream fileDecode;
    for(i = 0; i < 100; ++i)
    {
        fileDecode.open(decode.c_str());
        if( !fileDecode.good())
            return false;
        while(1)
        {
            string fileSign, fileCode;
            fileDecode >> fileSign >> fileCode;
            if(!fileDecode.fail())
                ReadCode(fileSign, fileCode, text);
            else
            {
                break;
            }
        }
    }
    return true;
}


int main()
{
    if(!ReadFiles("decode.txt", "text.txt"))
         cout << "Nie udalo sie otworzyc pliku" << endl;
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  vector<int> v;
  
  /*int a, cap, siz, max;
  
  
  for (a=1; a<100; a++)
  {
    
        for (int i = 1; i <= a; i++) 
            v.push_back(i);
        
        if(siz!=v.size() || cap!=v.capacity())
        {
            cout << "rozmiar: " << v.size() << endl;
            cout << "capacity: " << v.capacity() << endl;
            cout << "max_size: " << v.max_size() << endl << endl;
            siz=v.size();
            cap=v.capacity();
            max=v.max_size();
        }
  }
  */
  
  for (int i = 0; i <= 10; i++) 
            v.push_back(i);
  
  for (int i = 10; i > 0; i--)
  {
      v.erase(v.begin()+i);
  
            v.shrink_to_fit();
            cout << "rozmiar: " << v.size() << endl;
            cout << "capacity: " << v.capacity() << endl;
            cout << "max_size: " << v.max_size() << endl << endl;
  }
  
    
    return 0;
}

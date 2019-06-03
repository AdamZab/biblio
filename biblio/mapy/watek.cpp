#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>


std::mutex m;
std::condition_variable cv;
std::vector<std::string> data;
std::mutex _mutex;

/*void bar()
{
  
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::lock_guard<std::mutex> guard(barmutex);
   // std::cout << "koniec bar" << std::endl;
    
}*/

/*void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "koniec foo" << std::endl;
}*/

void push_data(const std::string &s){
    std::unique_lock<std::mutex> ul(_mutex);
    data.push_back(s);
    ul.unlock();
}

/*void worker(){
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, []{return true;});
}*/


int main() 
{
  /*std::thread first (foo);
  std::thread second (bar);  

  std::cout << "main, foo and bar now execute concurrently...\n";

  
  first.join();                
  second.join();               

  std::cout << "foo and bar completed.\n";*/
  
  std::thread t1(push_data, "alfa");
  std::thread t2(push_data, "beta");
  
  
 /* std::thread t1(worker);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  {
      std::lock_guard<std::mutex> lock(m);
      
  }
  std::cout << "sending signal" << std::endl;
  cv.notify_one();
  t1.join();*/


  return 0;
}

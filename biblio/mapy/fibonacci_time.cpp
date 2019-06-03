#include <iostream>
#include <chrono>
#include <ctime>
 
long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
 
auto start=0.0;
auto end=0.0;

class timer
{
private:
std:: string id;
std::chrono::time_point<std::chrono::steady_clock>t_start;

public:

timer():t_start(std::chrono::steady_clock::now()){};
timer(const std::string & s):id(s),t_start(std::chrono::steady_clock::now()){};

~timer(){ 
auto t_end = std::chrono::steady_clock::now();
std::chrono::duration<double> elapsed_seconds = t_end - t_start;
std::cout<< "timer:"<< id<<"elapsed:"<<elapsed_seconds.count()<<"s\n";

};

};


int main()
{


/*
 z cpp reference chrono
    auto start = std::chrono::system_clock::now();

    std::cout << "f(10) = " << fibonacci(10) << '\n';
    auto end = std::chrono::system_clock::now();
 
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

*/
timer t("my timer");
 int input = 30;
 std::cout<< "f("<<input<<")=" <<fibonacci(input)<<"\n";


}

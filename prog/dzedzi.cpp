#include <stdio.h>
#include <iostream>


using namespace std;

struct Human {
    void name() const noexcept {};
  protected:
    virtual void sex() const noexcept {}; 
};

struct Man : public Human {
    public:
        void sex() const noexcept override {};
};

int main(void)
{
    Man adam;
    adam.sex();
    
    return 0;
}

#include <iostream>





struct Base {
    virtual void f() {
        std::cout << "Base" << std::endl;
    }
    virtual ~Base() {
    }
};

struct Derived: Base {
    void f() override {
        std::cout << "Derived" << std::endl;
    }
    virtual ~Derived() {
    }
};

int main()
{
    Base b;
    Derived d;

    b.f();
    d.f();

    Base bb = d;
    bb.f();
    return 0;

}

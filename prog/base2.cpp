#include <iostream>

using namespace std;

struct Base {
    virtual void f() {
        cout << "Base" << endl;
    }
    virtual ~Base() {
    }
};

struct Derived: Base {
    virtual void f() override {
        cout << "Derived" << endl;
    }
    virtual ~Derived() {
    }
};

int main()
{
    Base b;
Derived d;

Base& rb = b;
Base& rd = d;

rb.f();
rd.f();

rb.Base::f();
rd.Base::f();

return 0;
}

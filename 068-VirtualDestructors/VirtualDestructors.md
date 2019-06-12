# Virtual Destructors

**TLDR:** Always mark your destructors (at least for classes that may be extended) as ```virtual```.

As the name implies this is a combination of [destructors](../026-Destructors/Destructors.md) and [virtual functions](../028-VirtualFunctions/VirtualFunctions.md).

Very important when dealing with polymorphism.

## Polymorphism without virtual destructors

```cpp
#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base Constructor\n"; }
    ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main()
{
    Base* base = new Base();
    delete base;
    std::cout << " ---------------- \n";
    Derived* derived = new Derived();
    delete derived;
}

// This prints
// Base Constructor
// Base Destructor
//  ----------------
// Base Constructor
// Derived Constructor
// Derived Destructor
// Base Destructor
```

## The problem that we are trying to solve

```cpp

int main()
{
    Base* base = new Base();
    delete base;
    std::cout << " ---------------- \n";
    Derived* derived = new Derived();
    delete derived;
    std::cout << " ---------------- \n";
    Base* poly = new Derived();
    delete poly;
}
// This will print
// Base Constructor
// Base Destructor
//  ---------------- 
// Base Constructor
// Derived Constructor
// Derived Destructor
// Base Destructor
//  ---------------- 
// Base Constructor
// Derived Constructor
// Base Destructor
```

As you can see the **Derived Destructor is not executed**, and that can cause memory leak.

## The simple solution

We just need to add the ```virtual``` keyword in our ```Base``` class destructor, and them the ```Derived``` destructor will be called correctly.

```cpp

class Base
{
public:
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

// This will print
// Base Constructor
// Base Destructor
//  ---------------- 
// Base Constructor
// Derived Constructor
// Derived Destructor
// Base Destructor
//  ---------------- 
// Base Constructor
// Derived Constructor
// Derived Destructor
// Base Destructor
```

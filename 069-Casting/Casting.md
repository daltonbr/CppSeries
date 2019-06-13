# Casting in C++

C++ is a **strongly typed language**, that evolved from C language, for that matter we could use **C style casting** as well as **C++ style casting** in C++ as expected.

One related topic to casting is ```implicit conversions```, which is a lossly cast, and so C++ (the compiler) knows how to convert the involved types, e.g. assigning an ```int``` to a ```double```.

```cpp
int a = 3;
double b = a;
```

Another topic is ```explicit conversions```, that we can see on the example bellow, where we jave this ```(int)``` (that is optional), but if we supply it, we are explicitly casting. This is a **C style casting**.

```cpp
double c = 3.14;
int d = (int)c;
```

## C++ style cast

There are four types of casts in C++. Technically, we can't do anything that we can't do with C style cast. What C++ style cast offers is more a **synthatic suggar** and some compilation-time checkings.
One exception is ```dynamic_cast``` that can return ```null``` in some cases.

A benefit of the C++ style casting is that they are **searchable**, and thus we can be more clear about our intents.

* ```static_cast```
* ```reinterpret_cast```    // Very related to [type punning](../066-TypePunning/TypePunning.md)
* ```dynamic_cast```
* ```const_cast```

```const_cast``` is basically used to add or remove ```const``` to something. You can add ```const``` implicitly either way, but in order to remove ```const``` we need to use ```const_cast```.

```cpp
double c = 3.14;
int d = static_cast<int>c;
```

```cpp
double c = 3.14;

// This is produce a compilation error
double d = reinterpret_cast<AnotherClass*>(&c);

// This will not produce a compilation error
double e = reinterpret_cast<AnotherClass*>(&c);
```

## Another example

```cpp
#include <iostream>

class Base
{
public:
    Base() {  }
    virtual ~Base() { }
};

class Derived : public Base
{
public:
    Derived() { }
    ~Derived() { }
};

class AnotherDerivedClass : public Base
{
public:
    AnotherDerivedClass() { }
    ~AnotherDerivedClass() { }
}

int main()
{
    Derived* derived = new Derived();

    Base* base = derived;

    //AnotherDerivedClass* another = static_cast<AnotherDerivedClass*>(base);

    // This cast CAN return null, if the intended cast isn't possible.
    AnotherDerivedClass* another = dynamic_cast<AnotherDerivedClass*>(base);

    if (another != null)
    {
        // Do stuff with another
    }
}
```

Related topic: Run Time Type Information (RTTI)

# Implicit Conversion and the Explicit Keyword in C++

[Video](https://www.youtube.com/watch?v=Rr1NX1lH3oE&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=41&t=12s)

**Implicit conversion** is an automatic conversion, the compiler will infer this conversion.

```cpp
#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name)
        : m_Name(name), m_Age(-1) {}
    Entity(int age)
        : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity)
{
    // Printing
}

int main()
{
    Entity a("Cherno"); // Equivalent Entity a = Entity("Cherno");
    Entity b(22);       // Equivalent Entity b = Entity(22);

    // Another ways of using implicit conversion
    //Entity a0 = "Dalton"; // "Dalton" is a const char, so it need to be converted to a string before being implicit converted to Entity
    Entity a = std::string("Cherno");
    Entity b = 22;

    // Use implicit conversion to instantiate an Entity, and them print it.
    PrintEntity(23);

    std::cin.get();
    return 0;
}
```

The `explicit` keyword disables the implicit conversion. We put this keyword in front of our constructor.

```cpp

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name)
        : m_Name(name), m_Age(-1) {}
    Explicit Entity(int age)
        : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity)
{
    // Printing
}

int main()
{
    // by using the 'explicit' keyword, this no longer works, we need to cast explicitly
    Entity a = 22;  

    // Explicit cast
    Entity b = (Entity)22;

    // Or use the constructor
    Entity c = Entity(22);

    Entity c
    std::cin.get();
    return 0;
}

```
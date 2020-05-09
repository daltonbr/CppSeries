# How to make your Strings faster in C++

[Video](https://www.youtube.com/watch?v=ZO68JEgoPeg&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=81&t=1s)

Main issue is that they allocate memory.
See [Stack vs Heap](./../054-StackVsHeapMemory/StackVsHeapMemory.md) note.

`std::string` loves to allocate!

```cpp
#include <iostream>
#include <string>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

void PrintName(const std::string& name)
{
    std::cout << name << std::endl;
}

int main()
{
    std::string name = "Yan Chernikov"; // allocation

    std::string firstName = name.substr(0, 3);  // allocation
    std::string lastName = name.substr(4, 9);  // allocation

    PrintName(name);

    std::cout << s_AllocCount << " allocation: << std::endl;
    std::cin.get();
}

```

This example above allocate 3 times.

To improve a bit, we can try to use some `std::string_view` ([documentation](https://en.cppreference.com/w/cpp/string/basic_string_view)) (since `C++17`), but in fact we could use a custom implementation of that.
The basic idea is to take a reference (a `const char*`) to the original string, when we want to create substrings.

```cpp

int main()
{
    std::string name = "Yan Chernikov"; // allocation

    std::string_view firstName(name.cst(), 3);
    std::string_view lastName(name.cst() + 4, 9);

    PrintName(name);

    std::cout << s_AllocCount << " allocation: << std::endl;
    std::cin.get();
}

```
Just 1 allocation!


```cpp

int main()
{
    const char* name = "Yan Chernikov"; // allocation

    std::string_view firstName(name, 3);
    std::string_view lastName(name + 4, 9);

    PrintName(name);

    std::cout << s_AllocCount << " allocation: << std::endl;
    std::cin.get();
}

```

zero allocations!
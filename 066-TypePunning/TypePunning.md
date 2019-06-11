# Type Punning in C++

This is a fancy term for us to just getting around the C++ type system.

In some languages we don't have a very well defined type system, we call them languages weakly typed.

We can for instance, just 'reinterpret' a struck or a class as a stream of bytes. Supposing that we don't have any pointers inside it.

## A very bad usage of type punning

```cpp
#include <iostream>

int main()
{
    int a = 50;
    // implicit conversion
    double value = a;

    // or explicit conversion
    double valueExplicit = (double)a;

    // 1st taking the integer pointer (&a)
    // 2nd casting it to a double pointer (double*)
    // 3rd dereference it (*)
    double value3 = *(double*)&a;

    // Consider that in this example sizeof(int) = 4 bytes (normally) and sizeof(double) = 8 bytes.
    // So we are taking uninitialized memory into our type punning.

    std::cout << value << std::endl;
}
```

## Another example

```cpp
#include <iostream>

// This struct is just 2 integers in memory, 2 * (sizeof(int))
struct Entity
{
    int x, y;
};

int main()
{
    Entity e = { 5, 8};
    int* position = (int*)&e;
    std::cout << position[0] << ", " << position[1] << std::endl;

    int y = *(int*)((char*)&e + 4);
    std::cout << y << std::endl;
}
```

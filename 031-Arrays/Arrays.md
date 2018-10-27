# Arrays in C++

[Arrays video](https://www.youtube.com/watch?v=ENDaJi08jCU&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=31)

Arrays are basically a pointers.
They go very well with for loops.
They store their data contiguously.
We need to keep tabs in the size of the array ourselves.

```cpp
#include <iostream>

int main()
{
    int example[5];  // create on the stack, will be terminated when go out of scope
    int* ptr = example;

    example[0] = 2;
    example[0] = 4;

    *(ptr + 2) = 6;

    std::cout << example[0] << endl;
    std::cout << example << endl;  // prints the memory address of the array

    std::cin.get();
}
```

Arrays in the heap

```cpp
#include <iostream>

int main()
{
    // this value need to be known at compile time
    static const int exampleSize = 5;

    // created on the heap, alive when destroyed manually
    int* another = new int[exampleSize];

    int example[exampleSize];

    for (int i = 0; i < exampleSize; i++)
    {
        example[i] = 2;
        another[i] = 2;
    }

    delete[] another;
}
```

If you want to return an array from your function, you should use the `new` keyword to allocated this array on the heap.

With `C++11` arrays we have a much safer code, but with the obvious overhead.

```cpp
#include <array>

// C++11
std::array<int, 5> another;
for (int i = 0; i < 5; i++)
{
    example[i] = 2;
}
```
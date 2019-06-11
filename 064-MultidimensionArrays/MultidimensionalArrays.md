# Multidimensional Arrays in C++

Multidimensional arrays in C++ are in face arrays of arrays, for as many dimensions do we have.

```cpp
#include <iostream>

int main()
{
    // Heap allocation -> 50 * sizeof(int) = 50 * 4 bytes
    // int* array = new int[50];

    // `array2d` is a buffer of pointer objects. A point to a collection of int pointers.
    int** array2d = new int*[50];
    for (int i = 0; i < 50; i++ )
    {
        array2d[i] = new int[50];
    }

    int*** array3d = new int**[50];
    for (int i = 0; i < 50; i++ )
    {
        array3d[i] = new int**[50];
        for (int j = 0; j < 50; j++ )
        {
            array3d[i][j] = new int[50];
            // this last line is the same as
            // int** ptr = array3d[i];
            // ptr[j] = new int[50];
        }
    }

    array[0][0][0] = 0;

    std::cin.get();
}

```

## Deleting multidimensional arrays

You need to go the most internal arrays and delete then from inside out, in order to avoid **memory leak**

```cpp
#include <iostream>

int main()
{

    // `array2d` is a buffer of pointer objects. A point to a collection of int pointers.
    int** array2d = new int*[50];
    for (int i = 0; i < 50; i++ )
    {
        array2d[i] = new int[50];
    }

    // If we do that, we just deallocate the 'outer' array.
    // All of the other integer are going to be still allocated.
    delete[] array2d;

    // The correct way of deleting it
    for (int i = 0; i < 50; i++)
    {
        delete[] array2d[i];
    }

    // and finally
    delete[] array2d;
```

## Memory fragmentation

When dealing with multidimensional arrays we need to pay atention to **memory fragmentation**.

Let's go with an example:

If we have an single array of 25 elements versus an array of 5x5 elements.
Instead of having a guaranteed continuous buffer, we get 5 sepparated buffers, and there is no guarantee that they will be contiguous.
So we are going to have possibly ```cache misses``` when trying to fetch those arrays elements.
So if perform is a concern (and normally is, right?) keep that in mind when choosing to use multidimensional arrays.

```cpp
int main()
{
    // `array2d` is a buffer of pointer objects. A point to a collection of int pointers.
    int** array2d = new int*[50];
    for (int i = 0; i < 50; i++ )
    {
        array2d[i] = new int[50];
    }

```

## A good alternative to replace multidimensional arrays

```cpp
int main()
{
    int* array = new int[5 * 5];
    for (int i = 0; i < 5 * 5; i++)
    {
        array[i] = 2;
    }

    // Emulating the bidimensional access.
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            array[x + y * 5] = 2;
        }
    }

```

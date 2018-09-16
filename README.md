# CppSeries

These are my personal notes and codes from an awesome [C++ Series by TheCherno](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

## Pointers

Pointers are just a variable that 'points' to a memory address, it holds an integer value. 

In a `x86` Application a memory address comprises 32 bits or 8 bytes, represented usually in hexadecimal, i.e. `0x001FFCA8`

In turn, these pointers are also stored in memory and have its own address.

In `C++11` we can use `nullptr`, instead of `NULL`
`NULL` is just a `#define NULL 0`, `nullptr` is a modern way to be 'extra-clear` about our intents.

Observation: Due to _Little Endian_ or _Big Endian_, you can see the memory allocating its value backwards. This is simply referred as the _'endianness'_ of our computer.

`0x001FFCA8`, could be represented as `A8 CA FF 01`

```cpp
void* ptr = NULL;
void* ptr = nullptr;
```

```cpp
int var = 8;
void* ptr = &var;
std::cin.get();
```

We can inspect the memory going to `DEBUG -> Windows -> Memory -> Memory 1` or `CTRL+ALT+M, 1`

```cpp
// char uses 1 byte, so we are using 8 bytes
// the 'new' keyword allocates memory in the heap
char* buffer = new char[8];

// setting 8 times, the value 0, starting at &buffer
memset(buffer, 0, 8);

// a pointer to a pointer
char** ptr = &buffer;

// dealocate our memory from the heap
delete[] buffer;
std::cin.get();
```

## References

[References video](https://www.youtube.com/watch?v=IzoFn3dfsPA&index=17&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

References are NOT a variable, that is why they need to be immediately assigned, i.e. `int& ref` gives us an error.


Pointers and references are similar, but they have subtle differences. References are like a 'syntactic sugar' for pointers.

Different from a regular variable, a reference when compiled is replaced by their original memory address and aren't a variable by itself.

```cpp
int a = 5;
int& ref = a;
std.cin.get();
```

We can now, pass a parameter **BY REFERENCE** to a function and after this function returns, the result persists, and the variable don't go **'out of scope'**.

```cpp
// this function receives a parameter BY REFERENCE, not BY VALUE
void Increment (int& value) { value++; }

int main()
{
    int a = 5;
    Increment(a);
    Log(a);
    std.cin.get();
}
```

Obs.: `*value++;` in this statement, we are going to increment first and then dereference this pointer later, it just how the precedence order works. In general we don't want that.

We can solve this by using parentheses: `(*value)++;`
Using references is a clearer way to communicate our intent.

**CAUTION:** References **can't be reassigned** to other variables, instead we can assign new addresses to that SAME variable

```cpp
int main()
{
    int a = 5;
    int b = 8;

    int& ref = a;
    ref = b;

    // a = 8, b = 8
}
```

Instead if we want to change a reference, we need to use a pointer
```cpp
int main()
{
    int a = 5;
    int b = 8;

    int* ref = &a;
    *ref = 2;
    ref = &b;
    *ref = 1;

    // a = 2, b = 1
}
```
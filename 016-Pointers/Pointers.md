# Pointers in C++

[Pointers video](https://www.youtube.com/watch?v=DTxHyVn0ODg&index=16&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

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

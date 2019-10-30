# How To Store Any Data in C++

**void pointer** (```void *ptr = &a;```) is a way to store any data, but it ISN'T the point of this lesson.

We are going to see the ```c++17``` way of do that.

```std::any``` (```c++17```) Why? Where? What did they eat?

```cpp
// c++17+ only
#include <iostream>
#include <any>

int main()
{
    std::any data;
    data = 2;
    data = "Cherno";
    data = std::string("Cherno");

    // could throw an exception if this type is not available.
    std::any_cast<std::string>(data);

    std::cin.get();
}
```

## Variant vs Any

```std::variant``` requires that you list all the possible types upfront (compile time), which seems worse, but it could be considered worser than ```std::any```, although this is what makes it **"type safer"**.

Digging deeper into the implementation of ```std::any``` we can see that for "small variables" like ```int```, ```float```, or something like ```vector4```'s (up until 32 bytes, and this is probably platform/implementation specific), we are getting static allocations, and internally it is handled like a traditional ```union```, whereas for "big variables" (like custom classes) we can get dynamic allocations.

```std::variant``` although will always using static allocation.

## Performance tip

Avoid copying data when constructing those types.

```cpp
// c++17+ only
#include <iostream>
#include <any>

int main()
{
    data1 = "Cherno";
    data2 = std::string("Cherno");

    // copying data =(
    std::string str1 = std::any_cast<std::string>(data);

    // constructing with a reference =)
    std::string& str2 = std::any_cast<std::string&>(data);
}
```

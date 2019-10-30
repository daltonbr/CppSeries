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

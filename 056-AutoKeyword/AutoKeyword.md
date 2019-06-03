# auto Keyword in C++

The concept is simple, ```auto``` keyword replaces the type in our definitions, and with that the compiler can determine the type of data that is being returned.

```cpp
#include <iostream>
#include <string>

int main()
{
    int a = 5;
    auto b = a;

    std::cin.get();
}
```

## Style and readability

If we change the function bellow to ```char* GetName()```, we don't need to change the declared type in the ```main``` function.
But that can also break a few things. So it could be good and bad.

Using ```auto``` can make our code different to read sometimes.

```cpp
#include <iostream>
#include <string>

std::string GetName()
{
    return "Cherno";
}

int main()
{
    auto name = GetName();
    

    std::cin.get();
}
```

## A good scenario to use auto

```cpp
#include <iostream>
#include <string>
#include <vector>

std::string GetName()
{
    return "Cherno";
}

int main()
{
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    for (std::vetor<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    // Here is an interesting spot for auto
    for (auto it = strings.begin(); it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cin.get();
}
```

Here also is a good spot for ```auto```.

```cpp

std::unordered_map<std::string, std::vector<Device*>> m_Devices;

```

But we can also use ```typedef``` or ```using```

```cpp
using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;

// or a typedef
typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;
```
# Multiple Types in a Single Variable

```std::variant``` is a new class in the standard library from C++17.
It's similar to ```std::optional```, it allows us not to worry about the exact data type of data whe are dealing with.

In C++17 and later, the std::variant class is a type-safe alternative for [unions](https://docs.microsoft.com/en-us/cpp/cpp/unions?view=vs-2019). See [67 - Unions](../067-Unions/Unions.md)

We specify a ```std::variant``` and then we list the data type that it can possibly be.

We may be parsing a file and we are not sure if this will be a string or an int.

Or maybe a command line and we are not sure if the params are going to be a float, double, int, or other things.

```cpp
#include <iostream>
#include <variant>

int main()
{
    std::variant<std::string, int> data;
    data = "Cherno";
    std::cout << std::get<std::string>(data) << std::endl;
    
    data = 2;
    std::cout << std::get<int>(data) << std::endl;

    std::cin.get();
}
```

## ```std::get```

```cpp

#include <iostream>
#include <variant>

int main()
{
    std::variant<std::string, int> data;
    data = "Cherno";
    std::cout << std::get<std::string>(data) << std::endl;
    
    std::cout << "sizeof(int)" << sizeof(int) << std::endl;
    std::cout << "sizeof(std::string)" << sizeof(std::string) << std::endl;
    std::cout << "sizeof(data)" << sizeof(data) << std::endl;

    if (auto value = std::get_if<std::string>(&data))
    {
        std::string& v = *value;
        std::cout << v << std::endl;
    }
    else
    {
        std::cout << "Not a string" << std::endl;
    }

    data = 2;
    data.index(); // in this case string is index 0, and int 1

    std::cout << std::get<int>(data) << std::endl;

    std::cin.get();
}
```

## Occupied space - Unions vs Variant

```std::variant``` uses the memory in a similar way to ```union``` so it will take the max size of the underlying types. But since we need something that will know what’s the currently active alternative, then we need to add some more space.

Plus everything needs to honour the alignment rules.

What’s more interesting is that std::variant won’t allocate any extra space! No dynamic allocation happens to hold variants. and the discriminator.

While you pay some extra space for all the type-safe functionality, it shouldn’t cost you regarding runtime performance.

Unions will be normally smaller than variants, but we loose type-safety. We should consider unions if we are in scenarios that we need to squeeze performance even further.

```cpp
#include <iostream>
#include <variant>

union MyUnion
{
    double myDouble;
    int myInt;
};

int main()
{

    MyUnion u;
    u.myInt = 5;
 
    std::variant<std::string, int> data;
    data = 5;

    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(std::string): " << sizeof(std::string) << std::endl;
    std::cout << "sizeof(float): " << sizeof(float) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;

    std::cout << "sizeof(MyUnion): " << sizeof(MyUnion) << std::endl;
    std::cout << "sizeof(data): " << sizeof(data) << std::endl;

    std::cin.get();

    /* Prints out
    sizeof(int): 4
    sizeof(std::string): 24
    sizeof(float): 4
    sizeof(double): 8
    sizeof(MyUnion): 8
    sizeof(data): 28
*/

```

## Another example

Following the example from previous topic [```std::optional```](../078-OptionalData/OptionalData.md)

```cpp
#include <iostream>
#include <variant>
#include <optional>

enum class ErrorCode
{
    None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, ErrorCode> ReadFileAsString()
{
    return {};
}
```

## Another good read

[Bartek's coding blog - std::variant](https://www.bfilipek.com/2018/06/variant.html)

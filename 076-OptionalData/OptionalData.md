# How to deal with Optional Data in C++

How to deal with data that may or may not to be there when we try to return it in a function? For instance, if we try to read a file, we may not be able to read that file (maybe we don't have the permission, or the file doesn't exist). We could for instance return an empty string, but that wouldn't be ideal either.

```std::optional``` is a new feature in C++17 that try to solve that kind of problem.

## The Bad way

In this case we check for an empty string

```cpp
#include <iostream>
#include <fstream>

std::string ReadFileAsString(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if (stream)
    {
        std::string result;
        // read file
        stream.close();
        return result;
    }

    return std::string();
}

int main()
{
    std::string data = ReadFileAsString("data.txt");

    if (data != "")
    {

    }
    return 0;
}
```

## A minor improvement

We set ```bool& outSuccess``` to true if we manage to get the file opened successfully.

```cpp
std::string ReadFileAsString(const std::string& filepath, bool& outSuccess)
```

## Using ```std::optional```

```cpp
#include <iostream>
#include <fstream>
#include <optional> // C++17

std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if (stream)
    {
        std::string result;
        // read file
        stream.close();
        return result;
    }

    return {};
}

int main()
{
    // or we can use auto
    std::optional<std::string> data = ReadFileAsString("data.txt");

    //or just: if (data)
    if (data.has_value())
    {
        std::cout << "File read successfully\n";
        std::string& str = *data;
        std::cout << str;
    }
    else
    {
        std::cout << "File could not be read\n";
    }

    std::cin.get();
    return 0;
}
```

## Some other tricks

Creating a default value in case we can't read it.

```cpp

std::string value = data.value_or("Not present");

std::optional<int> count;
int c = count.value_or(100);

```

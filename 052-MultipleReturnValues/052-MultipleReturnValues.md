# How to deal with multiple return values in C++

Technically in C++ we can return just one variable per function.

If we need to return two or more variables of the **same type** we can use vectors or arrays. (maybe not ideal)

Cherno's favorite way to handle this problem is to create a **struct** that contains all of our required variables to return.

One another solution is to pass parameters by reference in the signature of our methods.

```cpp
static void ParseShader(const std::string& fileName, std::string* outVertexShader, std::string* outFragmentShader);
```

In this example above we have vertexShader and fragmentShader being passed by reference, and then we can retrieve the processed results.

## Tuple

```cpp

#include<tuple>

static std::tuple<std::string, std::string> ParseShader(const std::string& filepath)
{
    // do stuff...
    return std::make_pair(vs, fs);
}

```

A tuple example

```cpp
#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int> TupleTest(std::string inputString, int inputInt)
{
    //return {inputString, inputInt};  // Error until C++17
    return std::make_tuple(inputString, inputInt);
}

int main()
{
    auto tuple = TupleTest("abcde", 42);

    std::cout << "string: " << std::get<0>(tuple) << std::endl;
    std::cout << "int: "    << std::get<1>(tuple) << std::endl;

    return 0;
}

/* -- Output

string: abcde
int: 42

*/

```
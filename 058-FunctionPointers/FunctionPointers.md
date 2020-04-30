# Function Pointers in C++

A way to assign a function to a variable.

You can pass functions as parameters for other functions, as a consequence of the statement above.

```cpp
#include <iostream>

void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

int main()
{
    auto function = HelloWorld;
    // This is the type of our function pointer, (that `auto` is replacing)
    // void(*function)() = HelloWorld;

    function();
    function();
}
```

In the example above, we are getting the address of that `HelloWorld` function, note that we just need to remove the `()` to make our intent clear, that we don't want to execute (or get the output of) the function.

```cpp
//Equivalent assignment, but more explicit.
// We don't need to use thee & because there is an implicit conversion.
auto function = &HelloWorld;
```

Since the type name of these function pointers are a little bit cumbersome, normally we can use `auto` or `typedef`'en into a more *"friednly"* type, basic creating an alias.

```cpp
void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

int main()
{
    typedef void(*HelloWorldFunction)();

    HelloWorldFunction function = HelloWorld;

    function();
}
```

## Now using parameters

```cpp
void HelloWorld(int a)
{
    std::cout << "Hello World! Value: " << a << std::endl;
}

int main()
{
    typedef void(*HelloWorldFunction)(int);

    HelloWorldFunction function = HelloWorld;

    function(8);
}
```

## An useful example

```cpp
#include <iostream>
#include <vector>

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<int> values = { 1, 5, 4, 2, 3};
    ForEach(values, PrintValue);

    // Or using a lambda
    ForEach(values, [](int value) { std::cout << "Value: " << std::endl; });
}
```

## Extra material

https://stackoverflow.com/questions/4295432/typedef-function-pointer
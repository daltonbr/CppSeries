# Lambdas in C++

Lambdas are essentially a way to define an *"anonymous"* function, a quick disposable one.

We thread this code more like a variable than a function.

Whenever you have a function pointer you could use a lambda.

A great use for lambdas is to pass them as **callbacks** to other API's.

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

```cpp
#include <iostream>

int main()
{
    std::vector<int> values = { 1, 5, 4, 2, 3};
    auto lambda = [](int value) { std::cout << "Value: " << std::endl; };

    ForEach(values, lambda);
}
```

## Captures

What goes inside the ```[]``` in the lambda call is called **captures**, this let us defined how we pass variables to the lambda. We can pass them by value or by reference.

## An example

Using ```std::find_if``` (we need to ```#include <algorithm```)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values = { 1, 5, 4, 2, 3};
    auto it = std::find_if (values.begin(), values.end(), [](int value) { return value > 3; });

    std::cout << *it << std::endl;
}
```

# Namespaces in C++

**Namespaces are designed to solve naming conflicts!**! That is it!

[cppreference for Namespaces](https://en.cppreference.com/w/cpp/language/namespace)

Namespaces provide a method for preventing name conflicts in large projects.

Symbols declared inside a namespace block are placed in a named scope that prevents them from being mistaken for identically-named symbols in other scopes.

Multiple namespace blocks with the same name are allowed. All declarations within those blocks are declared in the named scope.

The C Language doesn't have ```namespace``` (or something similar), that is why libraries that support C normally have the name of the library embbeded into their symbols (functions, variables) .e.g. ```gl_init``` from OpenGL.

```cpp
namespace apple {
    void print(const char* text)
    {
        std::cout << text << std::endl;
    }
}

namespace orange {
    void print(const char* text)
    {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

int main()
{
    apple::print("Printing in apple!");
    orange::print("Print Backwards in Orange");
    std::cin.get();
}
```

To avoid multiple nesting levels of indentations, could be interesting to write all our namespaces in one single line.!

```cpp
namespace first { namespace second { namespace third {
    void print(const char* text)
    {
        std::cout << text << std::endl;
    }
}}}

int main()
{
    first::second::third::print("Inception");
    std::cin.get();
}
```

Or for c++17

```cpp
namespace Q {
  namespace V { // V is a member of Q, and is fully defined within Q
// namespace Q::V { // C++17 alternative to the above two lines
```

## Using keyword and namespace alias

We can use the keywork ```using``` to specify what will be the default namespace used in some scope, or to create some alias for that namespace.

As a suggestion it's good to keep the scope of ```using``` as minimal as possible.
As a good rule of thumb, never use ```using``` in header files, because this will against the purpose of the namespaces, which is to avoid name conflicts.

```cpp

// a is now an alias for apple, and used outside of main scope.
namespace a = apple;

int main()
{
    // just for the scope of main()
    using namespace std;
    cout << "Hello" << endl;
    a.print();
}
```

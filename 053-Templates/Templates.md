# Templates in C++

Templates could be somewhat related to *Generics* from managed languages like Java or C#, nonetheless we have lots of differences and Templates are much more powerful.

Templates are like Macros, they let you do much more than Generics (that are tied to types). With Templates we program what the compiler will do at *compile-time*.

Template allows us to define a template (duh) that will be compiled but by your usage. The compiler write code for us, based on a set of rules. Like a blueprint.

## Templates to avoid overload functions

Template allows us to avoid writing lots of overloads to functions. So it can be helpful to avoid code duplication.

```cpp
#include <iostream>
#include <string>

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    Print(5);
    Print("Hello");
    Print(5.5f);
    std::cin.get();
}
```

Templates doesn't exists until we called then. The compiler will not evaluate it (at least not MSVC) if we don't use it, and therefore we don't get any kind of errors (in fact some compilers like Clang can try to look for errors in non-used templates).

We are not limited to *types*, we can create entire classes with templates.

## A class with templates

```cpp
#include <iostream>
#include <string>

template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N; }
};

int main()
{
    Array<int, 5> arrayInt;
    std::cout << arrayInt.GetSize() << std::endl;

    Array<std::string, 2> arrayString;
    std::cout << arrayString.GetSize() << std::endl;

    std::cin.get();
}

```

Templates can get very complex, and therefore can be difficult to evaluated later. That being said we should use then with care and thoughtful consideration.

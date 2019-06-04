# Static Arrays in C++

Arrays that cannot grow. The size is know at compile time.

It supports iterator, so we can use ```std::sort``` or ```myArray.begin()```

Arrays are store on the stack.
Arrays have bounce checking (optionally) if you compile a *debug* build.

Arrays doesn't store the size, the size is a template argument that we give it. (arrays are a template class)

```cpp
#include <iostream>
#include <array>  

int main()
{
    std::array<int, 5> data;
    std::cout << data.size() << std::endl;

    data[0] = 2;
    data[1] = 1;

    std::array<int, 5> dataOld;
    dataOld[0] = 0;

    std::cin.get();
}
```

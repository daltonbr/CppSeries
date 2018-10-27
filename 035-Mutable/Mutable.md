# Mutable

[Video](https://www.youtube.com/watch?v=bP9z3H3cVMY&index=35&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

"Something that can change"

Has 2 fairly different usages, one is related to [Const](../034-Const/Const.md); and the other is related to lambdas (not covered yet)

```cpp
#include <string>
#include <iostream> // std::cout

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;  // alowing const methods to change this
public:
    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName();

    int x = 8;

    // lambda function - a 'throw-away' function
    // this lambda is receiving parameters by value
    // marking this lambda as mutable, allow us to modify other variables
    auto f = [=]() mutable
    {
        x++;
        std::cout << "Hello" << std::endl;
    };

    f();
    // x = 8

    std::cin.get();
}
```
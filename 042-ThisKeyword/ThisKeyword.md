# This keyword in C++

[Video](https://www.youtube.com/watch?v=Z_hPJ_EhceI&index=43&t=0s&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

The `this` key is only accessible through a **member function** (a function that belongs to a class, so a method).  
`this` is a pointer to the current object instance that the method belongs to.

```cpp
#include <iostream>
#include <string>

void PrintEntity(Entity* e);

void PrintEntity2(const Entity& e);

class Entity
{
public:
    int x, y;

    Entity(int x, int  y)
    {
        // we can diffentiate, the the parameter from the class variables
        // x = x;

        Entity* e = this;

        // we can use `const` on the right side
        // that way we can stop the reassigning of that pointer

        Entity* const e = this;

        // using const, we don't allow the change from the next line
        // this = nullptr;

        e->x = x;

        // or simply

        this->x = x;
        this->y = y;

        Entity& e = *this;

        PrintEntity(this);
        // we just simply dereference the pointer in this signature
        PrintEntity2(*this);
    }

    // const here avoid reassigning `this`
    int GetX() const
    {
        return this->x;
    }

    void PrintEntity(Entity* e)
    {
        // Do your printing
    }
};
```
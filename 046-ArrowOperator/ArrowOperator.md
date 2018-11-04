# Arrow Operator

[Video](https://www.youtube.com/watch?v=4p3grlSpWYA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=46)

Essentially, the the **arrow operator** `->` is a shortcut for dereferencing a pointer.

```cpp
//instead of using
(*ptr).Print();

// we can use the arrow operator
ptr->Print();
```

```cpp
#include <string>
#include <iostream>

class Entity
{
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

int main()
{
    Entity e;
    e.Print();

    Entity* ptr = &e;
    
    // this next line doesn't work, because ptr is a pointer, not the Entity itself
    //ptr.Print();

    // we could dereference the pointer
    Entity& entity = *ptr;
    entity.Print();

    // one more way of dereferencing
    // we need the parenthesis because the operator precedence; '.' is evaluated before '*'
    (*ptr).Print();

    // the arrow operator is a shortcut for dereferencing a pointer
    ptr->Print();

    std::cin.get();
}
```

Sometimes could be interesting to override the arrow operator.

```cpp
#include <string>
#include <iostream>

class Entity
{
public:
    int x;
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity)
        : m_Obj(entity)
    {		
    }

    ~ScopedPtr()
    {
        delete m_Obj;
    }

    Entity* GetObject() { return m_Obj; }

    Entity* operator->()
    {
        return m_Obj;
    }

    // A version returning a const Entity, marking the operator as const too
    const Entity* operator->() const
    {
        return m_Obj;
    }
};

int main()
{
    ScopedPtr entity = new Entity();

    //this seems a little cumbersome
    entity.GetObject()->Print();

    // now overloading the arrow operator, seems more clean
    entity->Print();

    std::cin.get();
}
```

If we want to know what is the offset in memory of these variables, we could use the arrow operator

```cpp
#include <string>
#include <iostream>

struct Vector3
{
    // each float has 4 bytes
    // We could also rearrange the order of these variables, and it will work the same
    float x, y, z;
};

int main()
{
    int offset = (int)&((Vector3*)nullptr)->z;
    std::cout << offset << std::endl;

    std::cin.get();
}
```
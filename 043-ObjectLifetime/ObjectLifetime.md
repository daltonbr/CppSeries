# Object Lifetime in C++ (Stack/Scope Lifetimes)

```cpp
#include <string>
#include <iostream> // std::cout

class Entity
{
private:
    int x;
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }

};

int main()
{
    {
        // created in Stack
        Entity e;

        // created in Heap
        Entity* f = new Entity();
    }
    // e is out of the scope here, f is not

    std::cin.get();
}
```

A classical mistake, the following `int* CreateArray()` function, doesn't work as intended, because the returned array is going to be out-of-scope when this function returns.

```cpp
int* CreateArray()
{
    int array[50];
    return array;
}
```

Here we are emulating a type of **Smart Pointer**, called **Unique Pointer**.
This pointer is Stack allocated, using `new` keyword, but it is automatically deallocated for us, when the pointer goes out-of-scope.

```cpp
#include <string>
#include <iostream> // std::cout

class Entity
{
private:
    int x;
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
    {
    }

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main()
{
    {
        // created in Heap
        //Entity* e = new Entity();

        // allocated in Stack, but will be deallocated when go out-of-scope
        ScopedPtr f = new Entity();
    }
    // e and f will go out of the scope here

    std::cin.get();
}
```
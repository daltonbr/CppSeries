# Create/Instantiate Objects in C++

[Video](https://www.youtube.com/watch?v=Ks97R1knQDY&index=39&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&t=0s)

In C++ we can choose where to instantiate a new object,  in the **heap** or in the **stack**.

**Stack** objects have an **automatic lifespan**, as soon as the object go out-of-scope that object is gone. It's automatically handled for us. The objects in that _stack frame_ are freed up.

The **heap** is a different (and mysterious) place. Whenever an object is allocated in there, it will sits there until you actively deallocated it.

We should prefer to create objects on the **Stack** whenever is possible, it's the fastest way, the managed way.

## Stack Allocation

```cpp
    // Stack Allocation
    // Unlike C#, this will call the default constructor (not a null pointer)
    Entity entityStack0;
    // other ways to do it
    Entity entityStack1("Cherno");
    Entity entityStack2 = Entity("Dalton");

    std::cout << entityStack0.GetName() << std::endl;
```

### Reasons to not instantiate on the Stack

* Stack are usually small (when compared to Heap), around 1 or 2 MB, so if you need lots of memory, Heap is an option
* You need an object that lives beyond some scope.

## Heap Allocation

* We use **pointers** to hold the reference for Heap Allocation
* We use the `new` keyword
* Allocate on the Heap takes a hit in **performance**
* We need to **manually free up** this allocated memory later, we don't have a _Garbage Collector_ (GC) in C++, we achieve this with the `delete` keyword.

```cpp
// allocated in Heap
Entity* entity = new Entity("Cherno");
// deallocating
delete entity;
```

## Smart pointers

This is a subject for another time, but they are allocated in Heap and get that size advantage, they also control the memory deallocation for us.

```cpp
#include <string>
#include <iostream> // std::cout

class Entity
{
private:
    std::string m_Name;	
public:
    Entity() : m_Name("Unknown") {}
    Entity(const std::string& name)	: m_Name(name) {}

    const std::string& GetName() const { return m_Name; }
};

int main()
{
    // Stack Allocation
    // Unlike C#, this will call the default constructor (not a null pointer)
    Entity entityStack0;
    // other ways to do it
    Entity entityStack1("Cherno");
    Entity entityStack2 = Entity("Dalton");

    std::cout << entityStack0.GetName() << std::endl;
    // note that this pointer is out-of the scope of the curly brackets bellow.
    Entity* e;
    {
        Entity entityWillBeFreedUpSoon("Dilma");
        e = &entityWillBeFreedUpSoon;
        std::cout << entityWillBeFreedUpSoon.GetName() << std::endl;
    }
    // the pointer `e` is still valid, but it points to an unallocated memory now, 
    // entityWillBeFreedUpSoon is out-of-scope in this line.

    // Heap Allocation - the 'new' keyword
    Entity* entityHeap = new Entity("Cherno");
    delete entityHeap;

    std::cin.get();
}
```

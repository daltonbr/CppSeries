# Virtual Functions

[Virtual Functions in C++](https://www.youtube.com/watch?v=oIV2KchSyGQ&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=28)

the `virtual` keyword offer us a chance of override a method in the subclasses of the original class

A [virtual method table](https://en.wikipedia.org/wiki/Virtual_method_table) (VMT), virtual function table, virtual call table, dispatch table, vtable, or vftable is a mechanism used in a programming language to support **dynamic dispatch** (or run-time method binding).

```cpp
class Entity
{
public:
    std::string GetName() {return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}

    std::string GetName() { return m_Name; }
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("Cherno");
    PrintName(p);   // this uses the GetName method from the superclass Entity, and not from the Player class

    std::cin.get();
}

```

Now, the same example, using Virtual Functions

```cpp
class Entity
{
public:
    virtual std::string GetName() {return "Entity"; }   // we just need to add this virtual keyword
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}

    std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("Cherno");
    PrintName(p);   // Now we are executing the Player method GetName

    std::cin.get();
}

```

In C++11 we can mark the overridden function with the keyword `override`. Not required, but make our intentions clear and forces a override.

Virtual Functions aren't free.
There are 2 costs associated with it:

1. Additional memory to store a VTable
2. When the overridden method is called, we need to go over that table.

But this should be minor in most cases, excepted maybe in some embedded platforms when we need to squeeze every cycle.
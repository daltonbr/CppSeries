# Interfaces in C++ (Pure Virtual Functions)

[Interfaces in C++ Video](https://www.youtube.com/watch?v=UWAdd13EfM8&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=29)

Essentially the same as Abstract Classes in Java or C#.

It allows us to define a function in a base class that doesn't have an implementation, and 'force' other classes to implement that method.

Just to compare, Virtual Functions are optionally overridden.

In OOP it's common to create classes that only provides method signatures, this is also know as **Interfaces**, so we don't provide in those method implementations.

C++ doesn't use the `interface` keyword like C#, but it's basically the same concept.

```cpp
class Printable
{
public:
    // pure virtual funtion
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    // this is now a 'pure virtual function', making this an abstract class
    // and we no longer can instantiate it
    virtual std::string GetName() = 0;
    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}

    // Now we are obligated to implement this method
    std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    //PrintName(e);

    Player* p = new Player("Cherno");
    //PrintName(p);

    Print(e);
    Print(p);

    std::cin.get();
}

```
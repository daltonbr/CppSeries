# Dynamic Casting

The type system isn't enforced in C++, we can in fact cast from any type if we really want.

Dynamic cast it is specifically used for **cast along the inheritance hierarchy**.

**Dynamic cast** is one of the other [casting available](../069-Casting/Casting.md) in C++, provided as somewhat like a **safety net** for when we want a specific type of cast.

It does an extra work, to ensure that this cast is valid, this validation happens at **Run time**, as the other types of cast usually happens at Compile time. Because of that we have a small performance cost as one should expect.

We can Enable / Disable [RTTI (Run-Time Type Information)](https://en.wikipedia.org/wiki/Run-time_type_information) in Visual Studio by going to our **Project Properties** -> **C/C++** -> **Language** -> **Enable RTTI**. But then we are not allowed to use dynamic cast.

## Example

```cpp
class Entity
{
public:
    // we need to supply this to enforce a polimorphic class
    virtual void PrintName() {}
};

class Player : public Entity {};

class Enemy : public Entity {};

int main()
{
    Player *player = new Player();
    Entity *actuallyEnemy = new Enemy();

    Entity *actuallyPlayer = player;

    // p0 will cast
    Player* p0 = dynamic_cast<Player*>(actuallyPlayer);

    if (p0)
    {
        // do something with p0
    }

    // p1 will be a nullptr because the cast wasn't possible
    Player* p1 = dynamic_cast<Player*>(actuallyEnemy);

    if (p0)
    {
        // do something with p1
    }
```

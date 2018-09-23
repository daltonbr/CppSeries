# Inheritance

[Inheritance in C++ Video](https://www.youtube.com/watch?v=X8nYM8wdNRE&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=27)

Inheritance avoids code duplication

```cpp
#include <iostream>

class Entity
{
public
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity
{
    const char* Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    Player player;
    player.PrintName();
    player.Move(5f, 5f);
    player.X = 2f;

    std::cin.get();
}
```

Player is a **superset** of Entity.
Entity is a **subset** of Player.

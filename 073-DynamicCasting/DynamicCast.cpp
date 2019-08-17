#include <stdio.h>
#include <iostream>
#include <typeinfo>

class Entity
{
public:
    Entity(const char *_name)
        : name(_name) {}
    virtual ~Entity() {}
    virtual void PrintName()
    {
        std::cout << name << std::endl;
    }
    virtual const char* GetName()
    {
        return name.c_str();
    }
private:
    std::string name;
};

class Player : public Entity
{
public:
    using Entity::Entity;
    void Run()
    {
        std::cout << "Player " << GetName() << " is running" << std::endl;
    }
};

class Enemy : public Entity
{
public:
    using Entity::Entity;
    void BeBad()
    {
        std::cout << "Who's bad?" << std::endl;
    }
};

int main()
{
    Player *player = new Player("MyPlayer");
    Entity *actuallyPlayer = player;

    Entity *actuallyEnemy = new Enemy("MyEnemy");

    // C style cast
    Player* p1 = (Player *)actuallyPlayer;
    Player* p2 = (Player *)actuallyEnemy;
    p2->Run();

    // We could even use static cast
    //Player *p = static_cast<Player *>(actuallyPlayer);

    Player* p3 = dynamic_cast<Player*>(actuallyPlayer);
    Player* p4 = dynamic_cast<Player*>(actuallyEnemy);
    Player* p5 = static_cast<Player*>(actuallyEnemy);

    if (p3 != nullptr)
    {
        p3->Run();
    }
    else
    {
        std::cout << "Not a player" << std::endl;
    }
    

    if (p4 != nullptr)
    {
        p4->Run();
    }
    else
    {
        std::cout << "Not a player" << std::endl;
    }

    p5->Run();
    
}

# Classes in C++

By default all inside a class is `private`.

**Functions** inside a class are called **methods**.


```cpp
class Player
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

int main()
{
    // Using Default Constructor (created automatically for us)
    Player player1;

    player1.x = 5;
    player1.Move(1, -1);
}
```

## Classes vs Struct

[Video](https://www.youtube.com/watch?v=fLgTtaqqJp0&index=19&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

Technically:
Variables and methods in a **Class** are by default **private**, while **Structs** are by default **public**.

Structs exists in C++ as a way to maintain **back-compatibility** with **C** (the language), which doesn't have the concept of classes.

So Classes are basically very much similar to Structs.

In day to day, we normally uses Struct for 'plain old data', with not so many functionalities (methods). Yet, we could add some methods to a Struct.

Essentially, the difference is more a question of **design**.
Structs are not suited for **inheritance**, this is a very good distinction; it's a very _'oop-ish'_ concept.

```cpp
struct Vector2
{
    float x, y;
};
```
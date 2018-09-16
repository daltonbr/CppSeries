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
# Constructors

[Constructors in C++ Video](https://www.youtube.com/watch?v=FXhALMsHwEY&index=25&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

```cpp
class Entity
{
public:
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
    }

    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }

}

class Log
{
private:
    Log() {}    // a private hidden constructor
public:
    static void Write()
    {
    }

    // if we don't want to supply a default constructor we need to be explicit
    Log() = delete;
}

int main()
{
    Entity e1;
    e1.Print();

    Entity e2(10.0f, 5.0f)
    e2.Print();

    std::cin.get();
}
```

If we not provide a constructor, we get a 'default constructor' like this

```cpp
Entity() {}
```

In C++ we need to initialize even the primitive types, like `int`, `float`, etc.

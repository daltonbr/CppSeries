# Destructors

[Destructors in C++ Video](https://www.youtube.com/watch?v=D8cWquReFqw&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=260)

Destructor acts in heap and stack objects.

Destructor are special methods, that starts with `~` followed by the name of the class.

```cpp
class Entity
{
public:
    float X, Y;

    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" << std::endl;
    }

    // our destructor
    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }

}

void Function()
{
    Entity e;   // Creating on the stack
    e.Print();
}

int main()
{
    Function();

    std::cin.get();
}
```

Running the above code get, the Destructor gets called when the Entity e, gets out of scope.

For a real word example, if we need to manually clean any objects allocated in the heap, we can avoid memory leaks using Destructors.
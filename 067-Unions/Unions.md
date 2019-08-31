# Unions in C++

Unions is a bit like a struct or a class type, except that **it can only occupy the memory of one member at a time.**

It can be used in combination with type punning, and normally are used anonymously.

```cpp
#include <iostream>

int main()
{
    struct Union
    {
        union
        {
            float a;
            int b;
        };
    };

    Union u;
    u.a = 2.0f;
    std::cout << u.a << ", " << u.b << std::endl;
}

// will print the integer `2` (a)
// and that same integer interpreted as a float (b) 
// 2, 1073741824
```

## If we aren't using unions

```cpp
struct Vector4
{
    float x, y, z, w;

    /// This is a way to return the first two elements (x, y)
    /// without copying and allocating memory.
    /// 1st we get the address of x (&x)
    /// 2nd we cast it to (Vector2*)
    /// 3rd we dereference it to return an address (Vector2&) from the method signature
    /// (this is just a way around, if we not want to use unions)
    Vector2& GetA()
    {
        return *(Vector2*)&x;
    }
};
```

## An example

```cpp
#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{
    union
    {
        // Here `left` will be the same as `x, y`
        // and `right` will be the same as `z, w`
        struct
        {
            float x, y, z, w;
        };
        struct
        {
            Vector2 left, right;
        };
    };
};

void PrintVector(const Vector2& vector)
{
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    PrintVector(vector.left);
    vector.z = 500.0f;
    PrintVector(vector.right);

    std::cout << vector.x << ", " << vector.y << std::endl;
}
/// Will print
// 1, 2
// 500, 4
// 1, 2
```

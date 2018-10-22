# Operators and Operator Overloading in C++

[Video](https://www.youtube.com/watch?v=mS9755gF66w&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=41)

An **Operator** is a symbol that we use instead of a function to perform something.

Operator Overloading is the act of giving a new meaning to that operator.

We can define (or change, when it already exists) a behavior of an operator in your program. It's partially supported in C#, but not in Java.

```cpp
#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    // Pass by reference to avoid copying - the first const
    // and it doesn't modify this class - the second const
    Vector2 Add(const Vector2& other) const
    {
        return operator+(other);
        // other ways of doing the same thing
        //return Add(other);
        //return *this + other;
    }

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);		
    }

    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2& other) const
    {
        return Multiply(other);
    }

        bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const
    {
        return !(*this == other);		
    }
};

// Output stream, to overload to cout
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerUp(1.1f, 1.1f);

    Vector2 result = position.Add(speed.Multiply(powerUp));

    Vector2 result2 = position + speed * powerUp;

    std::cout << result2 << std::endl;

    std::cin.get();
    return 0;
}

```
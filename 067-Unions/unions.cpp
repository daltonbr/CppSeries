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

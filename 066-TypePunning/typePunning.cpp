#include <iostream>

// This struct is just 2 integers in memory, 2 * (sizeof(int))
struct Entity
{
    int x, y;
};

int main()
{
    Entity e = { 5, 8};
    int* position = (int*)&e;
    std::cout << position[0] << ", " << position[1] << std::endl;

    int y = *(int*)((char*)&e + 4);
    std::cout << y << std::endl;
    
}

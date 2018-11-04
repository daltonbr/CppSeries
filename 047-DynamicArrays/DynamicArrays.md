# Dynamic Arrays (std::vector)

[Video](https://www.youtube.com/watch?v=PocJ5jXv8No&index=48&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&t=2s)

```cpp
#include <string>
#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void NormalizeVertices(std::vector<Vertex>& vertices)
{
    for (Vertex& v : vertices)
    {
        double const magnitude = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        v.x /= magnitude;
        v.y /= magnitude;
        v.z /= magnitude;
    }
}

int main()
{	
    std::vector<Vertex> vertices;
    vertices.push_back({ 1, 2, 3 });
    vertices.push_back({ 4, 5, 6});

    for (int i = 0; i< vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }

    NormalizeVertices(vertices);

    // Here we copy the vertex inside the scope of the for-loop
    for (Vertex v : vertices)
    {
        std::cout << v << std::endl;
    }

    // To avoid copying, we just use a reference to that Vertex
    for (Vertex& v : vertices)
    {
        std::cout << v << std::endl;
    }

    vertices.clear();

    std::cin.get();
}
```

# Structured Bindings (C++17)

Structured Bindings [(a new feature from C++17)](https://en.cppreference.com/w/cpp/language/structured_binding) is a new feature that let us deal with multiple return values a little bit better.

## Example

```cpp
#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int>  CreatePerson()
{
    return { "Cherno", 24 };
}

int main()
{
    // Structured Bindings C++17
    auto[name, age] = CreatePerson();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}
```

### A more "real-world" example

By using Structured Bindings we could remove a ```struct ShaderProgramSouce``` that are being used just once in the entire code base, just to hold two parsed ```std::string```.

[Check this commit on the OpenGL study repo](https://github.com/daltonbr/OpenGL/commit/334b8c4090a0e541ddb03e41738ccad25d473e90)

```diff
#include <string>
#include <unordered_map>
+ #include <tuple>

#include "glm/glm.hpp"

- struct ShaderProgramSource
- {
-     std::string VertexSource;
-     std::string FragmentSource;
- };

class Shader
{
private:
-    ShaderProgramSource ParseShader(const std::string& filepath);
+    std::tuple<std::string, std::string> ParseShader(const std::string& filepath);

```

```diff
Shader::Shader(const std::string & filepath)
    : m_FilePath(filepath), m_RendererID(0)
{
-    ShaderProgramSource source = ParseShader(filepath);
-    m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
+    auto[vertexSource, fragmentSource] = ParseShader(filepath);
+    m_RendererID = CreateShader(vertexSource, fragmentSource);
}

-    ShaderProgramSource Shader::ParseShader(const std::string& filepath)
+    std::tuple<std::string, std::string> Shader::ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);
```

## Some ways to return values using ```std::pair```, ```std::tuple``` and ```std::tie```

The example bellow doesn't use struct (it could be another way to do that)

```cpp
#include <iostream>
#include <tuple>
#include <string>

// if we are only two values we could use <std::pair>, but with std::tuple we could expand
std::tuple < std::string, int>  CreatePerson()
{
    return { "Cherno", 24 };
}

int main()
{
    // using tuple (or pair)
    std::tuple<std::string, int> person = CreatePerson();

    // retrieving data from person
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    //// another way

    std::string name2;
    int age2;
    // pass the variables by reference
    std::tie(name, age) = CreatePerson();
}

```

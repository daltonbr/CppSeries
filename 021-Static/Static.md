# Static in C++

[Static Video - #021](https://www.youtube.com/watch?v=f3FVU-iwNuA&index=21&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

Static **outside** of a class: the linkage of that symbol that you declared is internal, it is only visible to that translation unit.

The Linker is not going to look outside of the scope of this translation unit.

A Static variable **inside** a Class or a Struct, it will share memory with all other instances of that Class/Struct

## External Linking (or Linkage) - Static Outside of a Class/Struct

### Main.cpp

```cpp
extern int s_Variable;

int main()
{
    std::cout << s_Variable << std::endl;
    std::cin.get();
}
```

### Static.cpp

```cpp
int s_Variable = 5;
```

if we put the keyword `static` outside of a class, this variable or method will be only visible to that file (translation unit)

A good idea is to mark your functions and variables Static (the ones outside classes), unless you need them to be linked across translation units.

## Static (inside) for Classes and Structs

The usage of `static` inside of a class/struct means that we are going to have **only one instance** of this variable/method across this class/struct, and they are accessible by all class instances, you access this static method/variable through the class itself and not by its instances.

### Main.cpp

```cpp
// we could use a class here, it doesn't matter
struct Entity
{
    static int x, y;

    // can reference only static variables
    static void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
}

int Entity::x;
int Entity::y;

int main()
{
    //Entity e1;
    Entity::x = 2;
    Entity::y = 3;

    //Entity e2;
    Entity::x = 5;
    Entity::y = 8;

    //e1.Print();
    //e2.Print();
    Entity::Print();

    std::cin.get();
}
```

### Static.cpp

```cpp
int s_Variable = 5;
```
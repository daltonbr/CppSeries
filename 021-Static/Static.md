# Static in C++

[Static Video - #021](https://www.youtube.com/watch?v=f3FVU-iwNuA&index=21&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

Static **outside** of a class: the linkage of that symbol that you declared is internal, it is only visible to that translation unit.

The Linker is not going to look outside of the scope of this translation unit.

A Static variable **inside** a Class or a Struct, it will share memory with all other instances of that Class/Struct

## External Linking (or Linkage) - Static Outside of a Class/Struct

_Main.cpp_
```cpp
extern int s_Variable;

int main()
{
	std::cout << s_Variable << std::endl;
	std::cin.get();
}
```

_Static.cpp_

```cpp
int s_Variable = 5;
```

if we put the keyword `static` outside of a class, this variable or method will be only visible to that file (translation unit)

A good idea is to mark your functions and variables Static (the ones outside classes), unless you need them to be linked across translation units.

## Static (inside) for Classes and Structs


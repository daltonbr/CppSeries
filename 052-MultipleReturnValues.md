# How to deal with multiple return values in C++

Technically in C++ we can return just one variable per function.

If we need to return two or more variables of the **same type** we can use vectors or arrays. (maybe not ideal)

Cherno's favorite way to handle this problem is to create a **struct** that contains all of our required variables to return.

One another solution is to pass parameters by reference in the signature of our methods.

```cpp
static void ParseShader(const std::string& fileName, std::string&vertexShader, std::string& fragmentShader);
```

In this example above we have vertexShader and fragmentShader being passed by reference, and then we can retrieve the processed results.

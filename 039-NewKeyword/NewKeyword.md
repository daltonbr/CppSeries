# New Keyword in C++

[Video](https://www.youtube.com/watch?v=NUZdUSqsCs4&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=39)

* `new` is a "deep keyword"
* `new` is very different than in managed languages like C# and Java.
* `new int` will "ask" for the OS to find 4 bytes of contiguous memory, and it will return a pointer to that memory address. This process will have it's own overhead, even though the OS are optmized to do this kind of operation. Just keep in mind that we have this overhead.
* Besides allocating the memory for us, `new` also calls the default constructor, if anyone is called (different than in C#, that will return a null pointer).
* `new` is an operator in C++, as `+`, `-`, or `%`; so it also can be overloaded.
  * Usually, `new` will call the c function `malloc, and then the default constructor
  * if used `new[]`, we should use `delete[]` also
* We can pass explicitly a memory to `new`
  * `Entity e* = new(ptr) Entity();`

```cpp
  // stack allocation
  int a = 2;
  // heap allocation (when using `new`)
  int* b = new int;
  int* c = new int[50];  // 200 bytes allocated

  // parentheses are optional
  Entity* e = new Entity();

  // allocated 10 times the sizeof(entity)
  Entity* eArray = new Entity[10];

  // Entity occupies 28 bytes
  std::cout << "size of one Entity object: " << sizeof(Entity) << std::endl;
```

```cpp
Entity e* = new Entity();

// This is basically the same thing that the line above
// except that we have the default constructor called for us.
// This is more `c style`
Entity e = (Entity*)malloc(sizeof(Entity));
```

* Always remember to call the `delete` keyword after using `new`
* `delete`, calls `free` and the `destructor`

```cpp
Entity e* = new Entity();


delete(e);

// the same as
free(e);
e.~Entity(e);
```
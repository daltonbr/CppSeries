# References in C++

[References video](https://www.youtube.com/watch?v=IzoFn3dfsPA&index=17&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

References are NOT a variable, that is why they need to be immediately assigned, i.e. `int& ref` gives us an error.


Pointers and references are similar, but they have subtle differences. References are like a 'syntactic sugar' for pointers.

Different from a regular variable, a reference when compiled is replaced by their original memory address and aren't a variable by itself.

```cpp
int a = 5;
int& ref = a;
std.cin.get();
```

We can now, pass a parameter **BY REFERENCE** to a function and after this function returns, the result persists, and the variable don't go **'out of scope'**.

```cpp
// this function receives a parameter BY REFERENCE, not BY VALUE
void Increment (int& value) { value++; }

int main()
{
    int a = 5;
    Increment(a);
    Log(a);
    std.cin.get();
}
```

Obs.: `*value++;` in this statement, we are going to increment first and then dereference this pointer later, it just how the precedence order works. In general we don't want that.

We can solve this by using parentheses: `(*value)++;`
Using references is a clearer way to communicate our intent.

**CAUTION:** References **can't be reassigned** to other variables, instead we can assign new addresses to that SAME variable

```cpp
int main()
{
    int a = 5;
    int b = 8;

    int& ref = a;
    ref = b;

    // a = 8, b = 8
}
```

Instead if we want to change a reference, we need to use a pointer
```cpp
int main()
{
    int a = 5;
    int b = 8;

    int* ref = &a;
    *ref = 2;
    ref = &b;
    *ref = 1;

    // a = 2, b = 1
}
```
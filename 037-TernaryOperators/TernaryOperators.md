# Ternary Operators in C++ (Conditional Assignment)

[Video](https://www.youtube.com/watch?v=ezqsL-st8qg&index=37&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

`<condition> ? <true-case-code> : <false-case-code>`;

The [ternary operator](https://www.cprogramming.com/reference/operators/ternary-operator.html) allows you to execute different code depending on the value of a condition, and the result of the expression is the result of the executed code. For example:

`int five_divided_by_x = ( x != 0 ? 5 / x : 0 );`

This operator is a syntactic sugar for a `if-else` statement

```cpp

static int s_Level = 1;
static int s_Speed = 2;

int main()
{
    if (s_Level > 5)
        s_Speed = 10;
    else
        s_Speed = 5;

    // it's the same as
    s_Speed = s_Level > 5 ? 10 : 5;

    std::string rank = s_Level > 10 ? "Master" : "Begginer";
}
```

```cpp
// nesting can become a little hard to read
// so you should consider avoiding
s_Speed = s_Level > 5 ? s_Level > 10 ? 10 : 5 : 5;

```
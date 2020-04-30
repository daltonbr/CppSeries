# Standard Library Algorithms

Not everything is a member function

## Collections, Algorithms, Iterators

## Say what you mean

Why make someone puzzle out your code?

Algorithms have names that are clues

Using `sort`, `find` and `generate` are much more expressive.

[Algorithm Documentation](https://en.cppreference.com/w/cpp/algorithm)

Less Fuss Over Style

i++
++i
In the for statement?
In the loop body?

Iterators vs. random access[]

Names for indices, iterators, etc.

```cpp
vector<int> v;

// instead of a traditional loop for filling a vector
for (int i = 0; i < 5; i++)
{
    v.push_back(i);
}

int i = 0;
std::generate_n(std::back_inserter(v), 5, [&]() {return i++;} );

// another example accumulating elements
int total = 0;
total = std::accumulate(begin(v), end(v), 0);

int count3 = std::coud(begin(v), end(v), 3); 
```

## Avoiding errors

Trying to remove elements from a vector with iterators this way will **invalidate the iterator**.

```cpp
vector<int> v {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};

for (auto it = begin(v); it != end(v); it++)
{
    if (*it == 3)
    {
        v.erase(it);
    }
}
```

One solution with algorithms
`remove_if` returns an iterator, which you can use later with `erase` to remove the desired items.

```cpp
vector<int> v {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};

auto endV = std::remove_if(begin(v), end(v), [](int elem) {return (elem == 3); });
v.erase(endV, end(v));
```

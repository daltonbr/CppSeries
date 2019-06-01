# Macros in C++

In the Preprocessor pass, the compiler basic make a 'text-edit' stage, in which we control what code is fed to the next compile stage. It basic is a *find and replace* but with a little more control.

Templates are evaluated later than Macros.

Macros, being such a broad an open subject, it can be used in different levels of complexity (like Templates), and as such, can decrease our code *readability*, specially for people that aren't used to it.

We can give values for our Preprocessor macros

```cpp
#define PR_DEBUG 0

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

int main()
{
    LOG("Hello");
    std::cin.get();
}
```

Or we can define our Preprocessor values 

```cpp
#define PR_DEBUG

#ifdef PR_DEBUG
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

int main()
{
    LOG("Hello");
    std::cin.get();
}
```

We can use multiline macros, just by inserting a ```\``` to escape the ```\n``` (also, don't leave any trailing spaces after the backslash, otherwise we will escape that space)

```cpp
#define MAIN int main() \
{\
    std::cin.get();\
}

MAIN
```

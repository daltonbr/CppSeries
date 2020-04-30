# Lambdas in C++

Lambdas are essentially a way to define an *"anonymous"* function, a quick disposable one.

We treat this code more like a variable than a function.

Whenever you have a function pointer you could use a lambda.

A great use for lambdas is to pass them as **callbacks** to other API's.

```cpp
#include <iostream>
#include <vector>

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<int> values = { 1, 5, 4, 2, 3};
    ForEach(values, PrintValue);

    // Or using a lambda
    ForEach(values, [](int value) { std::cout << "Value: " << std::endl; });
}
```

```cpp
#include <iostream>

int main()
{
    std::vector<int> values = { 1, 5, 4, 2, 3};
    auto lambda = [](int value) { std::cout << "Value: " << std::endl; };

    ForEach(values, lambda);
}
```

## Captures

What goes inside the ```[]``` in the lambda call is called **captures**, this let us defined how we pass variables to the lambda. We can pass them by value or by reference.

### An example

Using ```std::find_if``` (we need to ```#include <algorithm>```)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values = { 1, 5, 4, 2, 3};
    auto it = std::find_if (values.begin(), values.end(), [](int value) { return value > 3; });

    std::cout << *it << std::endl;
}
```

---

## Captures (take 2)

_From another course_[CPP Beyond the basics](https://app.pluralsight.com/library/courses/cplusplus-17-beyond-the-basics) with Kate Gregory

Empty `[]` - captures nothing, use only function parameters

`[x, y]` - capture x and y by value

* Copies are made
* Lambda can be used when x and y have gone out of scope

`[&x, &y]` - capture x and y by reference

* No copies, changes affect the originals
* Dangling references may be an issue

`[x=a+1, y=std::move(b)]` - alias or move capture

* Useful when you need it

`[=]` Copy "everything" by value

* Actually it's everything **used** in the body of the lambda. (the compiler trims what isn't used)

`[&]` Copy "everything" by reference

* Again, only what's used

`Mutable`

* Allows you to change values captures by reference

--

Lambda not stored -> capture by value or reference
Lambda stored -> capture by value

Use the "everything" notation

### Examples

```cpp
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!";
    }

    Entity(std::string name) :
        _name(name)
    {
        std::cout << "Created Entity " << _name << std::endl;
    }

    Entity(const Entity& entity);

    Entity& operator= (const Entity& rValue);

    ~Entity()
    {
        std::cout << "Destroyed Entity!";
    }

    std::string GetName() const { return _name; }

private:
    std::string _name;
};

int main()
{
    // Lambdas - a basic usage
    auto isEven = [](int input) {return input % 2 == 0; };
    auto isOdd = [](int input) {return input % 2 != 0; };

    bool is3Odd = isOdd(3);

    std::vector<int> nums = { 1, 2, 4, 5, 9 };

    int odds = std::count_if(nums.begin(), nums.end(), isOdd);
    int evens = std::count_if(nums.begin(), nums.end(), isEven);

    // Captures by value and reference explicitly [x, y, &message]
    // attention to message being captured by reference, in this case we are sure that this variable will not be out of scope.

    int x = 3;
    int y = 7;
    std::string message = "elements between ";
    message += std::to_string(x) + " and " + std::to_string(y) + " inclusive: ";

    std::for_each(begin(nums), end(nums),
        [x, y, &message](int n)
        {
            if (n >= x && n <= y)
            {
                message += " " + std::to_string(n);
            }
        });

    //

    x = y = 0;

    // x by value, rest by ref
    // x increment will NOT hold up (outside the lambda scope), because it's captured as a copy,
    // y increments will hold up, because it's capture by reference.
    std::for_each(begin(nums), end(nums),
        [&, x](int element) mutable
                {
                    x += element;
                    y += element;
                }
            );


    ///
    { // braces for scope
        auto pEntity = std::make_unique<Entity>(" Dalton ");

        std::for_each(begin(nums), end(nums),
            [=, &message](int n)
            {
                if (n >= x && n <= y)
                {
                    //Error, because share_ptr can't be copied (copy constructor)
                    //message += pEntity->GetName() + std::to_string(n);
                }
            });

        // pEntity not out of scope yet
        int i = 2;
    }

      // Alternative 1, dereferencing pEntity (although debatable)
      // in this specific case, we are sure that this pointer will not be dangling,
      // if you consider asynchronous scenarios we may not be sure anymore.
    {
        auto pEntity = std::make_unique<Entity>(" Dalton ");

        std::for_each(begin(nums), end(nums),
            [=, &message, &pEntity](int n)
            {
                if (n >= x && n <= y)
                {
                    message += pEntity->GetName() + std::to_string(n);
                }
            });

        // pEntity not out of scope yet
        int i = 2;
    }


    // alternative 2 - not right or wrong, just a different approach
    // use std::move, to move the ownership to to the inner (for_each) scope
    {
        auto pEntity = std::make_unique<Entity>(" Dalton ");

        std::for_each(begin(nums), end(nums),
            [=, &message, p = std::move(pEntity)](int n)
            {
                if (n >= x && n <= y)
                {
                    message += p->GetName() + std::to_string(n);
                }
            });

        // pEntity IS out of scope here
        int i = 2;
    }

    std::cout << message << std::endl;
    std::cin.get();
}

```

---

## Lambdas Returns

Lambdas **may** return a value.
Only a return statement in the lambda: return type **inferred** by compiler.
Compiled can't infer: developer specifies return type.

### Syntax

Returning a `double` in this lambda
`[](int n) -> double {...body_of_lambda }`

### Parameter

What to take?
Generally imposed by the place you are using it.
Like writing any other predicate.

## Syntactic Sugar

You could use function objects (functors), or even a [function pointer](../058-FunctionPointers/FunctionPointers.md) wherever you can use lambdas.

Lambdas keep the code where it is used

* For readability
* For expressivity (show your intent)
* For confidence no-one else uses this, so you can change it

## Summary

* Lambdas are "only" syntactic sugar
  * But they change everything
* Lambdas make `for_each` and other Standard Library functions suddenly usable.
* They open the door for interesting parallel and functional work
* C++ lambdas offer more control than other languages
  * Capturing by value/reference

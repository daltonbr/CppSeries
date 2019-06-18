# Precompiled Headers in C++

What are Precompiled Headers (PCH) ?

PCH give an opportunity to grab a bunch of header files, and convert them in a "compiled form" (a binnary format) that is way faster to deal with (than text).

PCH are useful for large projects.

**Essentially** PCH are a header file, in which you refer other header files that normally doesn't change frequently, like other libraries. That way the compiler can avoid recompile that specific part every time, thus reducing compilation times.

It avoid unnecessary compilation.
If you make any change to your project.

To use PCH, we just need to "inform" the compiler what headers we want to use for this PCH, and the compiler will just compile these separated headers once.

## What not to do with PCH

* Put everything (or almost everything) in the PCH.
Solution: Don't put frequently altered headers in there.

## What to do with PCH

* Put headers that you normally don't change, like the ```stl``` libraty or the Windows library ```windows.h```.
* If you finished working in a hipothetical *log* system you can add your own header into the PCH. (But avoid it when you are working on it).

## Downsides to PCH

* We can potentially hide what is being used/need in our project per file. So it can be harder to make our project more modular and can difficult its readability.

## How to do it

### Visual Studio

Put all the desired headers in a ```pch.h``` file (it can be any name you like). For Visual Studio we must have at least a *blank* ```pch.cpp``` to tag along. The only line of code we need to add in this file is a reference to its header, ```#include <pch.h>```.

For Visual Studio, we must right click on the ```pch.cpp``` and select ```Properties```. Then under ```C/C++``` -> ```PrecompiledHeaders``` and select ```Precompiled Header``` -> ```Create```.

After, right click on our desired **project** and select ```Properties```, again under ```C/C++ * Precompiled Headers```select ```Precompiled Header``` -> ```Use```; also we need to set ```Precompiled Header File``` -> ```pch.h```.

### GCC/Clang

In our folder we have

* ```Main.cpp```
* ```pch.cpp```
* ```pch.h```

// To compile while measuring time, we can use this line
```$ time g++ -std=c++11 Main.cpp```

// Creating the PCH (in fact just compiling it)
```$ g++ -std=c++11 pch.h```

That line generates a ```pch.h.gch```.

**NOTE**: to make a clean build delete the ```.exe``` generated file.

We are done, now we just need to compile again using the first line of code! Yay!

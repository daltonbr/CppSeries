# Using Dynamic Libraries in C++

Dynamic link, is a link that happens at run-time.

Static linking allows for more optmization.

We can have 'real' dynamic libraries usage, that is when our executable is completely independent of the dynamic lib; and there is a scenario of a 'in-between' dynamic library, when the executable requires the dll and have built in at least the pointers to the required functions.
That are good uses for both approaches.

Sometimes we need to declare functions differently if we are linking them dynamically or statically.

Mostly libraries support dynamic and static libraries with the same headers thought.

If linking with dynamic libraries, we need to supply the dll alongside our executable, at least in the same folder. We can also supply specific paths for these dll's.

## More on the subject

Interesting talk about dll's
[CppCon 2017: James McNellis “Everything You Ever Wanted to Know about DLLs](https://www.youtube.com/watch?v=JPQWQfDhICA)

http://CppCon.org

Presentation Slides, PDFs, Source Code and other presenter materials are available at https://github.com/CppCon/CppCon2017

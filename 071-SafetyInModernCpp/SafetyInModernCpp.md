# Safety in Modern C++

Some regular quotes from the community (not making any judgment value):

* What is the "correct way" of write C++ in "modern days"?
* "Be a man" an manage your own memory.

## What it is mean to be *safe*?

*Safe programming* (or the concept) aim to reduces crashes, memory leaks, access violations.

With ```C++11``` we are moving to concepts such *smart pointers* in favor of *raw pointers*.

The problem we are trying to solve: **allocate memory in the heap.** That is a big problem.

The language evolved (and is evolving) in order to reduce *human errors*. The idea behind the new concepts of the language is to make developers life easier and make more robust code bases.

I want to allocate a block of memory in the heap, and that memory exists until you explicitly delete it (*"raw pointer's way"*).

What happens if we forget to delete (deallocate) this memory?

* it could be harmless, we didn't even notice it.
* or could be catastrophic.s

Normally we should use *smart pointers* because they make our life easier and safer, but it's also ok to use *raw pointers* especially because it's good to understand how pointers work *"under the hood"*.

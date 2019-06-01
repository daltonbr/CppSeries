# Stack vs Heap Memory in C++

## TLDR

* **Stack allocation are much faster** (less expensive) than Heap allocation.
* Heap allocate happens when we use the ```new``` keyword.
* Heap allocated memory, needs to be deallocated with the ```delete``` keyword.
* Stack allocated memory, just get automatically freed up when they go out-of-scope.

Stack and Heap are two different types of memories.
When a program starts it gets divided into a bunch of places (memories) - there are more places than these two though.
Loosely, we can say that the Operating System, load the entire program into memory so the program can run.
The Stack and the Heap are two areas that we have in the RAM.
The Stack normally have a predefined size (normally around 2 Mb or so), and the Heap is also predefined, but can grow as our application runs and "asks" for more memory.

Now memory in our program is used to store data. Data read from files, values from variables, etc.

We can ask from C++ memory from Stack or from Heap.

The way memory are allocated for us is different in those two places.

Stack is much more fast than Heap. (Also because the memory is contiguosly allocated).

Using the ```new``` keyword allocated memory on the Heap, and then we need to release that memory ourselves (in C++).

The ```new```keywork just calls the function ```malloc``` and that will usually call the platform specific (OS normally) that will handle the memory management for us.

Event the ```malloc``` implementation can differ from system to system, it is generally a heavy operation, that need to make a lot of other tasks. So loosely speaking that is why allocating memory on Heap is more expensive than in Stack.

 And if you need more memory than what is initially allocated from ```malloc``` that can be also a task very expensive to do.
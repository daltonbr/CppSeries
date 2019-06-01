# Stack vs Heap Memory in C++

Stack and Heap are two different types of memories.
When a program starts it gets divided into a bunch of places (memories) - there are more places than these two though.
Loosely, we can say that the Operating System, load the entire program into memory so the program can run.
The Stack and the Heap are two areas that we have in the RAM.
The Stack normally have a predefined size (normally around 2 Mb or so), and the Heap is also predefined, but can grow as our application runs and "asks" for more memory.

Now memory in our program is used to store data. Data read from files, values from variables, etc.

We can ask from C++ memory from Stack or from Heap.

The way memory are allocated for us is different in those two places.

Stack is much more fast than Heap.

Using the ```new``` keyword allocated memory on the Heap, and then we need to release that memory ourselves (in C++).
# Using Libraries

[Video](https://www.youtube.com/watch?v=or1dAmUO8k0&index=50&t=124s&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

Cherno suggests that (for C++) we supply everything that we need within our repository.

In Visual Studio we can add the source code to other projects inside our Solution and compile it together.

We are linking with binaries in this lesson.

Normally in an C++ API we have two main folders **libraries** and **include** (basically the header files).

We have two approaches for linking **Static** and **Dynamic**.

We can try linking an OpenGL API [http://www.glfw.org/download.html](http://www.glfw.org/download.html). Let's use the pre-compiled 32-bit Windows Binaries. We also could put the source code inside our project, and compile it ourselves.

Files `.lib` are static libraries and `.dll` are the dynamic libraries.

After copying the `include` and `lib` folders into our Visual Studio project, we need to reference them into our **Project Properties**. Inside the Property pages of our project we go to `C/C++` -> `General` -> `Addition Include Directories`. Remember to verify what configuration is selected.

**TIP:** Here we can use the Visual Studio Tokens to use relative paths. If we are using CMAKE or Premake, we can also use their tokens.

Also in the **Property Pages** of our project, we need to supply the path to our libraries, we do this in `Linker` -> `Input` -> `Additional Dependencies`. E.g `glfw3.lib`

And in `Linker` -> `General` -> we specify our relative path to our libraries, so we can pass them in the `Input` field above, using just the file names. E.g. `HelloLinking\Dependencies\GLFW\lib-vc2015`
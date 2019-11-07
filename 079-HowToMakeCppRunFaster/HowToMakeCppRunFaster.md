# How to make Cpp run FASTER

c++11 introduce many useful multi-thread tools, one of them is ```std::async```

Fact: Multi-core processors are ubiquitous.

Figure out dependencies is one of most difficult challenges when trying to create a multi-threaded application.

In the example from the video, we are loading 19 times one asset (in order to create some simulate a heavy task)

```cpp
    void EditorLayer::LoadMeshes()
    {
        //...
        // Single-threaded loading
        for (const auto& file : meshFilepaths)
            m_Meshes.push_back(Mesh::Load(file));
        }
    }
```

EditorLayer.cpp

```cpp
#include <future>

    void EditorLayer::LoadMeshes()
    {
        //...
        // Multi-threaded loading
        for (const auto& file : meshFilepaths)
        {
            m_Futures.push_back(std::async(std::Launch::async, LoadMesh, &m_Meshes, file));
        }
    }

    static std::mutex s_MeshesMutex;

    // Helper class to fill the meshes vector
    static void LoadMesh(std::vector<Ref<Mesh>>* meshes, std::string filepath)
    {
        auto mesh = Mesh::Load(filepath);

        std::lock_guard<std::mutex> lock(s_MeshesMutex);

        //meshes need to be lock/unlocked with a mutex
        meshes->push_back(mesh);
    }
}
```

EditorLayer.h

```cpp
    std::vector<std::future<void>> m_Futures; // void is the returning type of the function `static void LoadMesh` 
```

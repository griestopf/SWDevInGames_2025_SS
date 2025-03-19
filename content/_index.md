+++
archetype = "home"
title = "Software-Entwicklung interaktiver Medien"
date = 2024-09-28T15:27:29+02:00
draft = false
weight = 0
+++


## Ablauf Vorlesung
- Bauen und Debuggen der Godot Engine
- C++ Crash Course
- Struktur ausgewählter Teile einer Game Engine am Beispiel von Godot
- Seminar
  - ENTWEDER ausgewählte Themen dem Bereich Game Engine Architechture
    - Theoretisch aufarbeiten 
    - In Godot-Sourcen erklären
  - ODER ausgewählte Themen im Skripting von Game Engines
    - Theoretisch aufarbeiten
    - In Godot beispielhaft anwenden


### Ausgewählte Themen Game Engine Architecture
- Szenengraph & Traversierung
- Physik
- Animation & Animation-Blending
- Material & Shader

### Ausgewählte Themen Game-Skripting
- 3rd Person Kamera in Räumen
- NPC Pathfinding
- ...

## Resourcen

- Buch: "Game Engine Architecture" Third Edition von Jason Gregory (ISBN 9781138035454)


<!--

## Lecture Pool

- Introduction to using Godot (done in Game Production?)
- Introduction to C++
  - History of C++
  - C++ in comparison to known languages
  - Hello, World
  - Concepts
    - Header Files
      - Separating class declaration (.h) and implementation (.cpp)
    - Compiled language
    - Compiling and Linking
    - Macros
    - Pointers
    - Standard Libraries
      - Std::
      - Boost
      - Project-wise
- The DNA of an interactive application (such as a game)
  - Init Things
  - Loop forever
    - Get Input
    - Process Input to parameterize output
    - Generate output (graphics, sound, ...)
- From the scene to the graphics card.
- Understanding the Godot Initialization and Main Loop 
  - [SceneTree](https://docs.godotengine.org/en/stable/classes/class_scenetree.html#class-scenetree) is the standard [MainLoop](https://docs.godotengine.org/en/stable/classes/class_mainloop.html#class-mainloop)
  - Any MainLoop implements _initialize, _process, _physics_process and _finalize.

- Debugging into Godot
  - From WinMain to widechar_main.
  - In widechar_main: 
    - Main::Start (main/main.cpp) initializes stuff
    - os.run() runs the application main loop
  - 
   
-->




<!--

|Day            | Topic                         | Description       | WebGL | Godot |
|---            |---                            |---                | ---   | --- |
|Fri, 16. May   | **[Hello Code 3]({{< ref "day_01_hello_code_3" >}})**    | Introduction to the course and setup instructions. | Setup editor, hello world | Install Godot, hello world |
|Tue, 20. May   | **[Rendering Pipeline]({{< ref "day_02_rendering_pipe" >}})**    | Overview of the rendering pipeline and its stages. | Triangle through pipeline | ? |
|Wed, 21. May   | **[Simple Cube]({{< ref "day_03_simple_cube" >}})**    | Creating and rendering a simple 3D cube. | Create simple 3D geometry | Loading assets in Godot |
|Thu, 22. May   | **[Perspective animated Cube]({{< ref "day_04_perspecitve_cube" >}})**    | Applying perspective projection to the cube. | Create animation loop with geoemtric transforms | What happens when you press play |
|Fri, 23. May   | **[Normals and Phong Shading]({{< ref "day_05_normals_phong" >}})**    | Understanding normals and implementing Phong shading. | Implement simple shader code | Shader editor and materials in Godot |
|Tue, 27. May   | **[Cylinder]({{< ref "day_06_cylinder" >}})**    | Modeling and rendering a 3D cylinder. | Implement cylinder code from math | ? |
|Wed, 28. May   | **[Scene Graph]({{< ref "day_07_scene_graph" >}})**    | Introduction to scene graphs and hierarchical transformations. | Implement small scene graph library (nodes, children, traversal) | Show scene graph |
|Fri, 30. May   | **[Robot Scene]({{< ref "day_08_robot_scene" >}})**    | Creating a complex scene with a robot model. | Use scene graph to create hierarchical robot model | Edit scene graph |
|Tue, 03. June  | **[Shader Techniques]({{< ref "day_09_shader_techniques" >}})**    | Exploring various shader techniques and effects. | Vertex shader that translates along normal | Working with shader editor |
|Mon, 04. June  | **[Shaders in Engines]({{< ref "day_10_shader_in_engines" >}})**    | Integrating shaders into game engines. | Toon shading | Texture access, material effects |

-->
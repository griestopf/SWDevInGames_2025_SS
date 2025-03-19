+++
title = 'Entwicklungsumgebung einrichten'
date = 2024-09-28T15:27:29+02:00
draft = false
weight = 10 
+++

## Lecture 1

- Godot Installieren (Produktiv)
- Godot Bauen
  - Visual Studio IDE Community installieren
    - C++ Workload
  - scons (Godot-Build-System) installieren
    - Python
    - pip scons
  - Godot Sourcen ziehen
  - Godot mit scons mit debug_symbols und als dev_build bauen
  - Mit scons eine Visual-Studio-Solution und Visual-Studio-Project-Dateien erzeugen: vsproj
- GitHub Copilot installieren
  - Bei GitHub als Student registrieren



## Resourcen

- Godot Docs: 
  - [Building from Source](https://docs.godotengine.org/en/stable/contributing/development/compiling/index.html#)
  - [Introduction to the build system](https://docs.godotengine.org/en/stable/contributing/development/compiling/introduction_to_the_buildsystem.html)
- Build Godot for debugging: 
  ```scons dev_build=yes debug_symbols=yes```
- Generate vsproj and sln files: 
  ```platform=windows vsproj=yes```


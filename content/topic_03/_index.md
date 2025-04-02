+++
title = 'C++ Eigenheiten: Speicher und Klassen'
draft = false
weight = 30 
+++

## Inhalte

- C++ basics
  - Eingebaute Datetypen
    - int
    - float/double
    - boolean
    - void
    - char
  - Struktur-Anweisungen
    - if/else
    - for/while
  - Deklarationen
    - Methoden/Funktions-Header
    - Klassen
- Die Speicher-"Verwaltung" in C++
  - managed vs. unmanaged
  - `new` und `delete`
- Reference vs. Value-Semantik
  - Pointer
  - Referenzen
- Arrays, Pointer und Strings
- Ein Notationssystem für Speicher-Inhalte
- Arrays (und Pointer)
- Eigene Datentypen (Klassen und Strukturen)
  - Konstruktoren und Destruktoren
  - Header (.h) und Code-Dateien (.cpp)


## Ressourcen

- [C++ built-in types](https://learn.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp?view=msvc-170)

- [VS Code für C++-Entwicklung in Windows konfigurieren](https://code.visualstudio.com/docs/cpp/config-msvc)
  - tasks.json verstehen und für die Verwendung mehrerer cpp-Files konfigurieren: 
    > You can modify your tasks.json to build multiple C++ files by using an argument like `${workspaceFolder}/*.cpp` instead of `${file}`. This will build all .cpp files in your current folder. You can also modify the output filename by replacing `${fileDirname}\\${fileBasenameNoExtension}.exe` with a hard-coded filename (for example `${workspaceFolder}\\myProgram.exe`).
    
  - launch.json verstehen und für das Debuggen einer aus mehreren cpp-Files bestehenden Applikation konfigurieren:
    > In the standard launch.json, `program` specifies the program you want to debug. Here it is set to the active file folder (`${fileDirname}`) and active filename with the `.exe` extension (`${fileBasenameNoExtension}.exe`), which if `helloworld.cpp` is the active file will be `helloworld.exe`. The args property is an array of arguments to pass to the program at runtime.


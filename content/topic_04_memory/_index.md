+++
title = 'Pointer und Memory-Management'
draft = false
weight = 40 
+++


## Source-Code-Aufteilung über mehrere Dateien in C++

In vielen neueren Sprachen kann Source-Code in wiederverwendbare Einheiten kompiliert werden. In C# sind das .dll-Dateien, in Java .jar-Files. Derartige Module erfüllen gleichzeitig zwei Aufgaben

1. Sie enthalten den vorkompilierten, direkt ausführbaren Code, der aus anderen Modulen aufgerufen werden kann.

2. Sie enthalten Informationen für den Compiler, so dass dieser Quell-Code, der die in den Modulen enthaltenen Code benutzt, korrekt übersetzen kann. 

In C++ gibt es diverse Formate für vorkompilierten Code, z. B. .lib, .dll oder .so-Dateien. Allen diesen Formaten ist gleich, dass dort KEINE Informationen für den Compiler enthalten sind, wie der darin enthaltene Code verwendet werden kann, sondern lediglich der für die Ausführung notwendige Maschinencode.

Das Gleiche gilt für die in einem Compile-Schritt von mehreren .cpp-Dateien erzeugten .obj-Dateien. Damit Code aus einer .cpp-Datei in einer anderen cpp-Datei verwendet werden kann, müssen alle notwendigen Informationen geteilt werden. Das geht über so genannte Header-Dateien. Header-Dateien enthalten C++-Source-Code. Allerdings sind dort üblicherweise nur _Deklarationen_ enthalten, also Klassen-Deklarationen und Funktions- und Methoden-_Signaturen_. Der eigentliche ausführbare Code, der in C++ immer in Funktions- und Methoden-Rümpfen (innerhalb von `{` und `}) steht, befindet sich dann in .cpp-Dateien.

Der deklarative Code in Header-Dateien kann dann per `#include`-Direktive in jede .cpp-Datei eingebunden werden, die den in der dazugehörigen Implementierungsdatei enthaltenen ausführbaren Code verwendet. `#include` wirkt dabei exakt so, als würde der Inhalt der einzubindenden (.h-)Datei an die Stelle der Include-Anweisung kopiert.

Um eine Methodenimplementierung (ein Methoden-Rumpf) in einer .cpp einer in einer Header-Datei deklarierten Klasse zuzuordnen wird die `<Klassenname>::<Methodenname>()`-Syntax verwendet.

Hier ein Beispiel für die Aufteilung einer einfachen Klasse in eine deklarative Header-Datei und den Implementierungsteil der Methoden in einer dazugehörigen .cpp-Datei.

### Header-Datei (.h)

```cpp
#ifndef MYCLASS_H
#define MYCLASS_H

// Class with a constructor and destructor
class MyExtClass { 
    public:
        MyExtClass();
        ~MyExtClass();
    
        int myData; // Member variable
        void myFunction();
    };

#endif
```


### Implementierungs-Datei (.cpp)

```cpp
#include "myextclass.h"
#include <iostream> 


// Class with a constructor and destructor
MyExtClass::MyExtClass() { std::cout << "Constructor called!" << std::endl; }
MyExtClass::~MyExtClass() { std::cout << "Destructor called!" << std::endl; }
    
void MyExtClass::myFunction() { std::cout << "Function called!" << std::endl; } // Member function
```

## Value-Semantik (automatische Variablen) vs. Reference-Semantik (pointer mit new/delete) vs. Smart Pointer.

Dieser Abschnitt erklärt, wie man in C++ mit **Objekten**, **Zeigern** und **Smart Pointern** umgeht – anhand der Beispielklasse `MyClass`.

Eine Ausnahme der Regel, dass .h-Dateien nur Deklarationen enthalten, sind C++_Templates_. Das sind Klasse-Schablonen, in denen ein oder mehrere verwendete Typen noch nicht bekannt sind. In anderen Programmiersprachen heißen solche Mechanismen auch _Generics_. In C++ erzeugt der Compiler erst bei Verwendung eines Templates eine konkrete Klasse. Daher werden üblicherweise auch die Implementierungen für Templates in Header-Dateien geschrieben.

---

### Klassen-Definition: `MyClass`

```cpp
#include <iostream>

class MyClass { 
public:
    MyClass() { std::cout << "Constructor called!" << std::endl; }
    ~MyClass() { std::cout << "Destructor called!" << std::endl; }

    int myData; // Member-Variable
    void myFunction() { std::cout << "Function called!" << std::endl; }
};
```

---

### Hauptfunktion: `main()`

```cpp
#include <iostream>
#include <memory> // Für smart pointers

int main() {

    if (true) {
        MyClass obj; // Objekt wird auf dem Stack erstellt
        obj.myData = 10; // Zugriff auf Member-Variable
    } // obj wird automatisch zerstört – Destruktor wird aufgerufen

    MyClass* objPtr = new MyClass(); // Objekt wird auf dem Heap erstellt
    objPtr->myData = 20; // Zugriff auf Member-Variable
    objPtr->myFunction(); // Aufruf der Member-Funktion
    delete objPtr; // Manuelles Löschen notwendig – Destruktor wird aufgerufen

    // unique_ptr – automatische Speicherverwaltung, exklusiver Besitz
    std::unique_ptr<MyClass> smartPtr(new MyClass());
    smartPtr->myData = 42;
    smartPtr->myFunction(); // Kein delete nötig – Zerstörung bei Gültigkeitsende

    // shared_ptr – gemeinsamer Besitz
    std::shared_ptr<MyClass> sharedPtr(new MyClass());
    sharedPtr->myData = 30;

    std::shared_ptr<MyClass> anotherSharedPtr = sharedPtr; // geteilte Besitzverhältnisse
    anotherSharedPtr->myData = 40;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

---

### Vergleich: Objektlebensdauer & Speicherverwaltung

| Art                  | Speicherort | Lebensdauer           | Automatisch gelöscht? | Bemerkung                  |
|----------------------|-------------|------------------------|------------------------|----------------------------|
| Stack-Objekt         | Stack       | Block/Funktion         | ✅                     | Einfach & sicher           |
| `new` + `delete`     | Heap        | manuell gesteuert      | ❌                     | Muss manuell gelöscht werden |
| `unique_ptr`         | Heap        | bei Gültigkeitsende    | ✅                     | Nur ein Besitzer           |
| `shared_ptr`         | Heap        | bei letztem Besitzer   | ✅                     | Mehrere Besitzer möglich   |

---

### Empfehlungen

- Verwende **Smart Pointer**, um Speicherlecks zu vermeiden.
- Bevorzuge **Stack-Objekte**, wenn kein dynamischer Speicher benötigt wird.
- Vermeide manuelles `new`/`delete`, außer in Spezialfällen.

---

## Implementierung eines benutzerdefinierten `SmartPointer` mit Referenzzählung

Dieser Abschnitt erklärt, wie man einen **einfachen referenzzählenden Smart Pointer** in C++ implementiert – ähnlich wie `std::shared_ptr`. Dieser `SmartPointer` verwaltet den Speicher eines Objekts automatisch und sorgt dafür, dass es nur gelöscht wird, wenn keine weiteren Referenzen darauf existieren.

---

### Code: `SmartPointer`-Klasse

```cpp
// Implementation of a reference counting smart pointer
template <typename T>
class SmartPointer {
private:
    T* ptr;        // Roher Zeiger auf das verwaltete Objekt
    int* refCount; // Zeiger auf den Referenzzähler

public:
    // Konstruktor
    SmartPointer(T* p = nullptr) : ptr(p), refCount(new int(1)) { }

    // Kopierkonstruktor
    SmartPointer(const SmartPointer& sp) : ptr(sp.ptr), refCount(sp.refCount) {
        (*refCount)++; // Referenzzähler erhöhen
    }

    // Destruktor
    ~SmartPointer() {
        if (--(*refCount) == 0) {
            delete ptr;       // Objekt löschen
            delete refCount; // Zähler löschen
        }
    }

    // Dereferenzierungsoperator (*)
    T& operator*() { return *ptr; }

    // Zugriff auf Member (->)
    T* operator->() { return ptr; }

    // Zuweisungsoperator: anderer SmartPointer
    SmartPointer& operator=(const SmartPointer& sp) {
        if (this != &sp) {
            if (--(*refCount) == 0) {
                delete ptr;
                delete refCount;
            }
            ptr = sp.ptr;
            refCount = sp.refCount;
            (*refCount)++;
        }
        return *this;
    }

    // Zuweisungsoperator: von rohem Zeiger
    SmartPointer& operator=(T* p) {
        if (ptr != p) {
            if (--(*refCount) == 0) {
                delete ptr;
                delete refCount;
            }
            ptr = p;
            refCount = new int(1);
        }
        return *this;
    }
};
```

---

###  Wie funktioniert das?

####  Referenzzählung (Reference Counting)

Der Smart Pointer verwaltet zwei Dinge:

- `ptr`: Einen rohen Zeiger auf das verwaltete Objekt
- `refCount`: Einen Zeiger auf einen Ganzzahlwert, der zählt, wie viele `SmartPointer`-Instanzen gerade das Objekt teilen

Wenn die Anzahl der Referenzen (`refCount`) auf **null** fällt, wird das Objekt und der Zähler **automatisch gelöscht**.

---

### Beispielverwendung

```cpp
#include <iostream>

int main() {
    SmartPointer<int> sp1(new int(5));
    {
        SmartPointer<int> sp2 = sp1; // refCount = 2
        std::cout << *sp2 << std::endl; // Ausgabe: 5
    } // sp2 geht aus dem Gültigkeitsbereich, refCount = 1

    std::cout << *sp1 << std::endl; // Ausgabe: 5
} // sp1 wird zerstört, refCount = 0 → Speicher wird freigegeben
```

---

### Vorteile dieser Implementierung

- Automatisches Speicher-Management  
- Geteilter Besitz mehrerer SmartPointer  
- Kein `delete` notwendig für den Benutzer  
- Weniger Risiko für Speicherlecks oder doppelte Freigaben

---

### Hinweise & Grenzen

- Kein **Thread-Safety** (anders als `std::shared_ptr`)
- Kein **Move-Semantik-Support**
- Kein **WeakPointer-Konzept**
- Kein Schutz vor **Zyklischen Referenzen**

---


### Fazit

Diese Implementierung eines `SmartPointer<T>` zeigt die Grundidee von **Shared Ownership mit Referenzzählung**. In echten Projekten empfiehlt es sich aber, `std::shared_ptr` oder `std::unique_ptr` aus `<memory>` zu verwenden, da diese optimierter, sicherer und vollständiger implementiert sind.



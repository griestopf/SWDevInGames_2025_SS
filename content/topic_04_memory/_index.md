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
### Templates

Eine Ausnahme der Regel, dass .h-Dateien nur Deklarationen enthalten, sind C++_Templates_. Das sind Klasse-Schablonen, in denen ein oder mehrere verwendete Typen noch nicht bekannt sind. In anderen Programmiersprachen heißen solche Mechanismen auch _Generics_. In C++ erzeugt der Compiler erst bei Verwendung eines Templates eine konkrete Klasse. Daher werden üblicherweise auch die Implementierungen für Templates in Header-Dateien geschrieben.

---

## Value-Semantik (automatische Variablen) vs. Reference-Semantik (pointer mit new/delete) vs. Smart Pointer.

Dieser Abschnitt erklärt, wie man in C++ mit **Objekten**, **Zeigern** und **Smart Pointern** umgeht – anhand der Beispielklasse `MyClass`.

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

### Managed vs. Unmanaged

In den meisten der aktuell verwendeten Programmiersprachen wie C#, Python, Java, JavaScript, Typescript ist es möglich, Objekte in Referenz-Semantik ("auf dem Heap") zu erzeugen, ohne sich darum kümmern zu müssen, dass der dafür reservierte Speicher oder weitere von den Objekten verwendete Ressourcen wieder frei gegeben werden, sobald das Objekt nicht mehr benötigt wird. Das geht, weil in diesen Sprachen eine Speicherverwaltung eingebaut ist, die jedes während des Programmlaufs angeforderte Memory-Häppchen überwacht. Von Zeit zu Zeit läuft dann ein *Garbage Collector* und gibt nicht mehr benutzten Speicher frei. Auf Grund dieser nicht unerheblichen Verwaltungs-Mechanik, die in jedes noch so kleine Programm in diesen Sprachen automatisch eingebaut ist, werden diese Sprachen auch _managed_ genannt. 

In C++ existiert kein solcher eingebauter Mechanismus, daher zählt C++ zu den _unmanaged_ Programmiersprachen. Eine weitere aktuelle Programmiersprache, die ebenfalls unmanaged ist, weil kein Garbage Collector existiert, ist **Rust**. Im Gegensatz zu C++ verfügt Rust über andere, einfachere Mechanismen (ein so genanntes *ownership* System), um die üblichen Speicherfehler (Speicher nicht allokiert, speicher bereits frei gegeben) zu umgehen.

Um in C++ ebenfalls eine rudimentäre Speicherverwaltung zu implementieren, die die häufigsten Fehler im Umgang mit unmanaged Speicher zu umgehen, verwendet man häufig so genannte SmartPointer mit Referenz-Zählung.

Dieser Abschnitt erklärt, wie man einen **einfachen referenzzählenden Smart Pointer** in C++ implementiert – ähnlich wie `std::shared_ptr`. Dieser `SmartPointer` verwaltet den Speicher eines Objekts automatisch und sorgt dafür, dass es nur gelöscht wird, wenn keine weiteren Referenzen darauf existieren.

---

### Code: `SmartPointer`-Klasse

```cpp
// Implementierung eines referenzzählenden Smart Pointers
template <typename T>
class SmartPointer {
private:
    T* ptr;                 // Zeiger auf das verwaltete Objekt
    unsigned* refCount;    // Zeiger auf den Referenzzähler

public:
    // Konstruktor
    SmartPointer(T* p = nullptr) : ptr(p), refCount(new unsigned(1)) {}

    // Kopierkonstruktor
    SmartPointer(const RefCountedSmartPointer& other) 
        : ptr(other.ptr), refCount(other.refCount) {
        ++(*refCount); // Referenzzähler erhöhen
    }

    // Zuweisungsoperator
    SmartPointer& operator=(const SmartPointer& other) {
        if (this != &other) {
            release(); // Aktuelles Objekt freigeben
            ptr = other.ptr;
            refCount = other.refCount;
            ++(*refCount); // Referenzzähler erhöhen
        }
        return *this;
    }

    // Destruktor
    ~SmartPointer() {
        release(); // Objekt freigeben
    }

    // Dereferenzierungsoperator
    T& operator*() const { return *ptr; }

    // Zugriff auf Member
    T* operator->() const { return ptr; }

    // Gibt die Anzahl der Referenzen zurück
    unsigned use_count() const { return *refCount; }

private:
    // Freigabe des verwalteten Objekts
    void release() {
        if (--(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }
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

### Was bedeutet das `template<typename T>` und das `T`?

Ein C++ Template ist eine generische Schablone (hier für eine Klassendeklaration), die es ermöglicht, Klassen oder Funktionen für verschiedene Datentypen zu definieren, ohne den Code mehrfach schreiben zu müssen. In obigem Code wird ein Template (template <typename T>) verwendet, um die Klasse SmartPointer generisch zu gestalten. Der Platzhalter T steht für den Datentyp des verwalteten Objekts, der erst bei der Instanziierung der Klasse festgelegt wird (z. B. SmartPointer<int> für einen int). Dadurch kann der SmartPointer beliebige Objekttypen verwalten, ohne dass für jeden Typ eine eigene Klasse geschrieben werden muss.

Templates in C++ werden üblicherweise in Header-Dateien geschrieben, weil sie zur Kompilierzeit vollständig definiert sein müssen. 



### Fazit

Diese Implementierung eines `SmartPointer<T>` zeigt die Grundidee von **Shared Ownership mit Referenzzählung**. In echten Projekten empfiehlt es sich aber, `std::shared_ptr` oder `std::unique_ptr` aus `<memory>` zu verwenden, da diese optimierter, sicherer und vollständiger implementiert sind.



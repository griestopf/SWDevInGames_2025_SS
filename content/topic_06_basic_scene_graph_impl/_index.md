+++
title = 'Mein erster Szenengraph'
draft = false
weight = 60 
+++

## Class Library

Mit den Erkenntnissen der ersten Godot-Source-Code-Analyse sollen nun die wichtigen Bestandteile in einer eigenen Applikation nachgebaut werden.

Zunächst soll die Applikation keine grafische Ausgabe erzeugen, sondern im Source-Code nur die Strukturen nachbauen. Dazu genügt es, eine Konsolen-Applikation wie die ersten "Hello, World"-Übungen zu erzeugen. Ausgaben können mit `printf` auf der Konsole dazu genutzt werden, um dem Programm beim Arbeiten zuzusehen.

In einer späteren Lektion können wir dann versuchen, dem Programm einen Unterbau unterzuschieben, der tatsächlich grafische Ausgaben erzeugt.

### Object, RefCounted, etc.

Entwirf eine an Godot's 3D-Klassen angelehnte Klassenbibliothek, die es erlaubt, aus Instanzen hierarchische Strukturen zu erzeugen. Eine Klasse namens `Node` (die aber eher an Godot's `Node3D` angelehnt ist) sollte dabei weit oben in der Hierarchie stehen. Jede Node sollte in der Lage sein, eine Liste von Kind-Nodes zu enthalten. Ebenfalls weit oben in der Klassen-Hierarchie sollten die üblichen 3D-Transformation-Eigenschaften (Position, Rotation, Skalierung) verankert sein. Implementiere eine spezielle, virtuelle Methode namens `Render` in `Node` die beim Iterieren des Szenegraphen zu Render-Zwecken aufgerufen wird.

Von `Node` abgeleitete Klassen übernehmen spezielle Aufgaben. Identifiziere einige erste "sinnvolle" Klassen, wie z. B. `MeshInstance3D` (Name darf anders sein, z.B. `MeshInstance`), die visuelle Bausteine einer 3D-Szene darstellen. Implementiere die `Render`-Methoden durch spezielle Konsolen-Ausgaben (Name, Typ und Eigenschaften der Node).

Simuliere `Resources` zunächst mit 2-3 Klasse (`Mesh`, `Texture`). Sorge dafür, dass die Lebenszeit zumindest dieser Klassen mittels Reference-Counting gemanagt wird.

### Main Loop, Iteration

Strukturiere die `main`-Funktion in einen Initialisierungs- und einen Game-Loop-Teil. Erstelle im Initialisierungs-Code einen Beispiel-Szenengraphen aus den Bestandteilen der Szenen-Klassenbibliothek. Im Rumpf der Game-Loop, traversiere den Szenengraphen und sorge dafür, dass für jede besuchte Node deren `Render`-Methode aufgerufen wird.


## Szenen-Traversierung

### Wie macht es Godot?

Versuche, herauszufinden, wie in Godot der Traversierungsmechanismus des Szenengraphen funktioniert.

- Wo ist die Liste von Kind-Objekten einer Node gespeichert?
- Finde den Code, der die Schleife enthält, die über die Kind-Liste iteriert
  - In welcher Klasse ist diese Methode enthalten?
- Welche Aktionen werden beim "Besuch" einer Node während der Traversierung ausgelöst?
- Wie ist die Polymorphie implementiert, also das z. B. beim Besuch einer `MeshInstance3D`-Node anderer Code ausgeführt wird, als beim Besuch einer `Camera3D`-Node?

### Visitor-Pattern? 

- Vergleiche den (möglicherweise) in Godot implementierten Polymorphie-Ansatz für Nodes mit dem Visitor-Pattern in der Literatur.
- Implementiere einen eigenen Ansatz, der sich an Godot, an das Visitor-Pattern oder ein Mittelding daraus anlehnt.


## Resourcen

- [Beispiel-Implementierung der Szenengraph-Klassen](https://github.com/griestopf/SWDevInGames_2025_SS/tree/main/_example_code/L04_Scratch)
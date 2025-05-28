#include <iostream>
#include <memory>
#include "meshinstance3d.h"


class Elter
{
public:
    virtual void TuWas()
    {
        std::cout << "Elter::TuWas aufgerufen" << std::endl;
    }
};

class Kind : public Elter
{
public:
    virtual void TuWas()
    {
        std::cout << "Kind::TuWas aufgerufen" << std::endl;
    }
};


int main() {

    Elter *elter = new Elter();
    Kind *kind = new Kind();

    elter->TuWas(); // Aufruf der Methode in der Basisklasse
    kind->TuWas(); // Aufruf der Methode in der abgeleiteten Klasse

    Elter *irgendwas = kind;
    irgendwas->TuWas(); 

    Node3D* root = new Node3D("Root");
    Node3D* child1 = new Node3D("Child1");
    MeshInstance3D* child2 = new MeshInstance3D("Child2");
    root->addChild(child1);
    root->addChild(child2);

    MeshInstance3D* grandChild1 = new MeshInstance3D("GrandChild1");
    child1->addChild(grandChild1);

    MeshInstance3D* grandChild2 = new MeshInstance3D("GrandChild2");
    child1->addChild(grandChild2);

    Ref<Mesh> mesh1 = Ref<Mesh>(new Mesh("Mesh1"));
    grandChild1->setMesh(mesh1);

    Ref<Mesh> mesh2 = Ref<Mesh>(new Mesh("Mesh2"));
    grandChild2->setMesh(mesh2);
    child2->setMesh(mesh1);

    root->render();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}

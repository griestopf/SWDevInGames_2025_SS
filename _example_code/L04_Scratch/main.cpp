#include <iostream>
#include <memory>
#include "meshinstance3d.h"


class Tier
{
public:
    virtual void TuWas()
    {
        std::cout << "Tier::TuWas aufgerufen" << std::endl;
    }
};

class Katze : public Tier
{
public:
    virtual void TuWas()
    {
        std::cout << "Katze::Miau" << std::endl;
    }    
};


class Hund : public Tier
{
public:
    virtual void TuWas()
    {
        std::cout << "Hund::Wuff" << std::endl;
    }
};


int main() {

    /*
    Tier *tier = new Tier();
    tier->TuWas(); 

    Katze *katze = new Katze();
    katze->TuWas();
    
    Hund *hund = new Hund();
    hund->TuWas();

    // Create an array of Tier pointers
    // and call TuWas on each of them
    Tier *tiere[] = {tier, katze, hund};
    for (Tier *t : tiere) {
        t->TuWas();
    }
    */


    Node3D* root = new Node3D("Root");
    
    Node3D* child1 = new Node3D("Child1");
    MeshInstance3D* child2 = new MeshInstance3D("Child2");
    root->addChild(child1);
    root->addChild(child2);

    MeshInstance3D* grandChild1 = new MeshInstance3D("GrandChild1");
    child1->addChild(grandChild1);

    MeshInstance3D* grandChild2 = new MeshInstance3D("GrandChild2");
    child1->addChild(grandChild2);

    Node3D* grandChild3 = new Node3D("GrandChild3");
    child2->addChild(grandChild3);

    Ref<Mesh> mesh1 = Ref<Mesh>(new Mesh("Mesh1"));
    grandChild1->setMesh(mesh1);

    Ref<Mesh> mesh2 = Ref<Mesh>(new Mesh("Mesh2"));
    grandChild2->setMesh(mesh2);
    child2->setMesh(mesh2);



    root->render();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}

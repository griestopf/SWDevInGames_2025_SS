#ifndef MESHINSTANCE3D_H
#define MESHINSTANCE3D_H
#include "node3d.h"
#include "ref.h"
#include "mesh.h"
class MeshInstance3D : public Node3D
{
public:
    MeshInstance3D();
    ~MeshInstance3D();
    Ref<Mesh> getMesh();
    void setMesh(Ref<Mesh> mesh);

private:
    Ref<Mesh> mesh;
}

#endif // MESHINSTANCE3D_H

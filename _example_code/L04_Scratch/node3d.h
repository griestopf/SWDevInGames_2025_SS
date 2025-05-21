#ifndef NODE3D_H
#define NODE3D_H
#include "object.h"
#include <unordered_map>
#include <string>
class Node3D : public Object
{
public:
    Node3D();
    ~Node3D();

private:
    std::unordered_map<std::string, Node3D *> children;
    // TODO: Add transformation properties.
};

#endif // NODE3D_H
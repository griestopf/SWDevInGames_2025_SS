#ifndef REF_H
#define REF_H

#include "refcounted.h"


class Ref : public RefCounted {
    RefCounted *reference;


public:
    Ref(RefCounted *p_reference = nullptr);
    Ref(const Ref &p_ref);
    ~Ref();
    Ref &operator=(const Ref &p_ref);
    RefCounted *get() const;
}
#endif // REF_H
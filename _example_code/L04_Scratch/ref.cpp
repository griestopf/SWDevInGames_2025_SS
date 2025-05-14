
#include "ref.h"


Ref::Ref(RefCounted *p_reference = nullptr) : reference(p_reference) {
    if (reference) {
        reference->reference();
    }
}

Ref::Ref(const Ref &p_ref) : reference(p_ref.reference) {
    if (reference) {
        reference->reference();
    }
}

Ref::~Ref() {
    if (reference) {
        reference->unreference();
    }
}

Ref &Ref::operator=(const Ref &p_ref) {
    if (this != &p_ref) {
        if (reference) {
            reference->unreference();
        }
        reference = p_ref.reference;
        if (reference) {
            reference->reference();
        }
    }
    return *this;
}

RefCounted *Ref::get() const { return reference; }
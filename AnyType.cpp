#include <stdlib.h>

#include "AnyType.hpp"

class UnTypedMPunsafe
{
    friend class UnTypedMP;
    friend class AnyType;
    void *var;
    int size;

public:
    UnTypedMPunsafe(int _size);
};

UnTypedMPunsafe::UnTypedMPunsafe(int _size)
    : var(malloc(_size)), size(_size) {}

////////////////////////////

UnTypedMP::UnTypedMP(int _size)
    : u(_size) {}
void *UnTypedMP::GetVar() { return u.var; }
int &UnTypedMP::GetSize() { return u.size; }
UnTypedMP::~UnTypedMP() { free(u.var); }
UnTypedMP &UnTypedMP::operator=(const UnTypedMP &a)
{
    if (this != &a)
    {
        free(GetVar());
        u.var = malloc(a.u.size);
        u.size = a.u.size;
        int i;
        unsigned char *buf_from = (unsigned char *)a.u.var;
        unsigned char *buf_to = (unsigned char *)u.var;
        for (i = 0; i < u.size; i++)
            buf_to[i] = buf_from[i];
    }
    return *this;
}

////////////////////////////

AnyType::AnyType() : ptr(new UnTypedMP(sizeof(void *))) {}
AnyType::AnyType(const AnyType &a)
{
    ptr = new UnTypedMP(a.ptr->u.size);
}
AnyType::~AnyType() { delete ptr; }

////////////////////////////

void AnyType::Destroy()
{
    delete ptr;
    ptr = 0;
}
void AnyType::Swap(AnyType &a)
{
    UnTypedMP *temp = a.ptr;
    a.ptr = ptr;
    ptr = temp;
}
AnyType &AnyType::operator=(const AnyType &a)
{
    if (this != &a)
    {
        if (!ptr)
            ptr = new UnTypedMP;
        *ptr = *a.ptr;
    }
    return *this;
}

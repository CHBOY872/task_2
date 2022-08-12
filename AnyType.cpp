#include <stdlib.h>

#include "AnyType.hpp"

UnTypedMPunsafe::UnTypedMPunsafe(int _size)
    : var(malloc(_size)), size(_size) {}

////////////////////////////

UnTypedMP::UnTypedMP(int _size)
    : UnTypedMPunsafe(_size) {}
UnTypedMP::~UnTypedMP() { free(var); }
UnTypedMP &UnTypedMP::operator=(const UnTypedMP &a)
{
    if (this != &a)
    {
        free(var);
        var = malloc(a.size);
        size = a.size;
        int i;
        unsigned char *buf_from = (unsigned char *)a.var;
        unsigned char *buf_to = (unsigned char *)var;
        for (i = 0; i < size; i++)
            buf_to[i] = buf_from[i];
    }
    return *this;
}

////////////////////////////

AnyType::AnyType() : ptr(new UnTypedMP(sizeof(void *))) {}
AnyType::AnyType(const AnyType &a)
{
    ptr = new UnTypedMP(a.ptr->size);
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

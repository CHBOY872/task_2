#include <stdlib.h> // for malloc, free

#include "Exception.hpp"
#include "AnyType.hpp"

class UnTypedMPunsafe // unsafe point
{                     // inaccessible for clients
    friend class UnTypedMP;
    friend class AnyType;
    void *var;
    int size;

public:
    UnTypedMPunsafe(int _size);
    ~UnTypedMPunsafe();
};

UnTypedMPunsafe::UnTypedMPunsafe(int _size)
    : var(malloc(_size)), size(_size) {}
UnTypedMPunsafe::~UnTypedMPunsafe() { free(var); }

////////////////////////////

UnTypedMP::UnTypedMP(int _size)
    : u(new UnTypedMPunsafe(_size)) {}
void *UnTypedMP::GetVar() { return u->var; }
int &UnTypedMP::GetSize() { return u->size; }
UnTypedMP::~UnTypedMP() { delete u; }
UnTypedMP &UnTypedMP::operator=(const UnTypedMP &a)
{
    if (this != &a)
    {
        delete u;
        u = new UnTypedMPunsafe(a.u->size);
        int i;
        unsigned char *buf_from = (unsigned char *)a.u->var;
        unsigned char *buf_to = (unsigned char *)u->var;
        for (i = 0; i < u->size; i++)
            buf_to[i] = buf_from[i];
    }
    return *this;
}

////////////////////////////

AnyType::AnyType() : ptr(new UnTypedMP(sizeof(void *))) {}
AnyType::AnyType(const AnyType &a)
{
    ptr = new UnTypedMP(a.ptr->u->size);
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

bool AnyType::ToBool()
{
    if (sizeof(bool) != ptr->GetSize())
        throw ExceptionType(sizeof(bool), ptr->GetSize());
    return *(bool *)ptr->GetVar();
}

char AnyType::ToChar()
{
    if (sizeof(char) != ptr->GetSize())
        throw ExceptionType(sizeof(char), ptr->GetSize());
    return *(char *)ptr->GetVar();
}
unsigned char AnyType::ToUChar()
{
    if (sizeof(unsigned char) != ptr->GetSize())
        throw ExceptionType(sizeof(unsigned char), ptr->GetSize());
    return *(unsigned char *)ptr->GetVar();
}

short AnyType::ToShort()
{
    if (sizeof(short) != ptr->GetSize())
        throw ExceptionType(sizeof(short), ptr->GetSize());
    return *(short *)ptr->GetVar();
}
unsigned short AnyType::ToUShort()
{
    if (sizeof(unsigned short) != ptr->GetSize())
        throw ExceptionType(sizeof(unsigned short), ptr->GetSize());
    return *(unsigned short *)ptr->GetVar();
}

int AnyType::ToInt()
{
    if (sizeof(int) != ptr->GetSize())
        throw ExceptionType(sizeof(int), ptr->GetSize());
    return *(int *)ptr->GetVar();
}
unsigned int AnyType::ToUInt()
{
    if (sizeof(unsigned int) != ptr->GetSize())
        throw ExceptionType(sizeof(unsigned int), ptr->GetSize());
    return *(unsigned int *)ptr->GetVar();
}

long AnyType::ToLong()
{
    if (sizeof(long) != ptr->GetSize())
        throw ExceptionType(sizeof(long), ptr->GetSize());
    return *(long *)ptr->GetVar();
}
unsigned long AnyType::ToULong()
{
    if (sizeof(unsigned long) != ptr->GetSize())
        throw ExceptionType(sizeof(unsigned long), ptr->GetSize());
    return *(unsigned long *)ptr->GetVar();
}

long long AnyType::ToLongLong()
{
    if (sizeof(long long) != ptr->GetSize())
        throw ExceptionType(sizeof(long long), ptr->GetSize());
    return *(long long *)ptr->GetVar();
}
unsigned long long AnyType::ToULongLong()
{
    if (sizeof(unsigned long long) != ptr->GetSize())
        throw ExceptionType(sizeof(unsigned long long), ptr->GetSize());
    return *(unsigned long long *)ptr->GetVar();
}

float AnyType::ToFloat()
{
    if (sizeof(float) != ptr->GetSize())
        throw ExceptionType(sizeof(float), ptr->GetSize());
    return *(float *)ptr->GetVar();
}
double AnyType::ToDouble()
{
    if (sizeof(double) != ptr->GetSize())
        throw ExceptionType(sizeof(double), ptr->GetSize());
    return *(double *)ptr->GetVar();
}
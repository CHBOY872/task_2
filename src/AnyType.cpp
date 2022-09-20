#include <iostream>
#include <stdlib.h>

#include "AnyType.hpp"
#include "Exception.hpp"

UnTypedMP::UnTypedMP(const char *_type, unsigned char _size)
    : var(malloc(_size)), size(_size)
{
    type = _type;
}
UnTypedMP::UnTypedMP(const UnTypedMP &a)
    : var(malloc(a.size)), type(a.type), size(a.size)
{
    unsigned char *from = (unsigned char *)a.var;
    unsigned char *to = (unsigned char *)var;
    unsigned char i;
    for (i = 0; i < size; i++)
        *(to + i) = *(from + i);
}
UnTypedMP::~UnTypedMP() { free(var); }
void *UnTypedMP::GetVar() { return var; }

////////////////////////////////

AnyType::AnyType() : ptr(0) {}
AnyType::AnyType(const AnyType &a) : ptr(new UnTypedMP(*(a.ptr))) {}

AnyType::~AnyType()
{
    if (ptr)
        delete ptr;
}

AnyType &AnyType::operator=(const AnyType &a)
{
    if (this != &a)
    {
        if (ptr)
            delete ptr;
        ptr = new UnTypedMP(*(a.ptr));
    }
    return *this;
}

void AnyType::Destroy() // destroy object
{
    if (ptr)
        delete ptr;
}
void AnyType::Swap(AnyType &a) // Swap 2 AnyTypes objects
{
    UnTypedMP *tmp = a.ptr;
    a.ptr = ptr;
    ptr = tmp;
}

bool AnyType::ToBool()
{
    return ToSomeType<bool>();
}

char AnyType::ToChar()
{
    return ToSomeType<char>();
}
unsigned char AnyType::ToUChar()
{
    return ToSomeType<unsigned char>();
}

short AnyType::ToShort()
{
    return ToSomeType<short>();
}
unsigned short AnyType::ToUShort()
{
    return ToSomeType<unsigned short>();
}

int AnyType::ToInt()
{
    return ToSomeType<int>();
}
unsigned int AnyType::ToUInt()
{
    return ToSomeType<unsigned int>();
}

long AnyType::ToLong()
{
    return ToSomeType<long>();
}
unsigned long AnyType::ToULong()
{
    return ToSomeType<unsigned long>();
}

long long AnyType::ToLongLong()
{
    return ToSomeType<long long>();
}
unsigned long long AnyType::ToULongLong()
{
    return ToSomeType<unsigned long long>();
}

float AnyType::ToFloat()
{
    return ToSomeType<float>();
}
double AnyType::ToDouble()
{
    return ToSomeType<double>();
}

template <class T>
T AnyType::ToSomeType()
{
    if (std::string(typeid(T).name()) != ptr->type)
        throw ExceptionType();
    return *(T *)ptr->GetVar();
}
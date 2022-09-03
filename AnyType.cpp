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

AnyType::AnyType() : var(0) {}
AnyType::AnyType(const AnyType &a) : var(new UnTypedMP(*(a.var))) {}

AnyType::~AnyType()
{
    if (var)
        delete var;
}

AnyType &AnyType::operator=(const AnyType &a)
{
    if (this != &a)
    {
        if (var)
            delete var;
        var = new UnTypedMP(*(a.var));
    }
    return *this;
}

void AnyType::Destroy() // destroy object
{
    if (var)
        delete var;
}
void AnyType::Swap(AnyType &a) // Swap 2 AnyTypes objects
{
    UnTypedMP *tmp = a.var;
    a.var = var;
    var = tmp;
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
    if (std::string(typeid(T).name()) != var->type)
        throw ExceptionType();
    return *(T *)var->GetVar();
}
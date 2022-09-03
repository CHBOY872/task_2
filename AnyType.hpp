#ifndef ANYTYPE_HPP_SENTRY
#define ANYTYPE_HPP_SENTRY

#include <typeinfo>
#include <string>

class AnyType;
class UnTypedMP
{
    friend class AnyType;
    void *var;
    std::string type;
    unsigned char size;

public:
    UnTypedMP(const char *_type, unsigned char _size);
    UnTypedMP(const UnTypedMP &a);
    ~UnTypedMP();
    void *GetVar();
};

class AnyType // main AnyType class
{
    UnTypedMP *ptr;

public:
    AnyType();
    template <class T>
    AnyType(T a) : ptr(new UnTypedMP(sizeof(T))) // conversion constructors
    {                                            // for types
        *(T *)ptr->GetVar() = a;
    }
    AnyType(const AnyType &a);

    ~AnyType();

    AnyType &operator=(const AnyType &a);

    void Destroy();
    void Swap(AnyType &a);

    bool ToBool();

    char ToChar();
    unsigned char ToUChar();

    short ToShort();
    unsigned short ToUShort();

    int ToInt();
    unsigned int ToUInt();

    long ToLong();
    unsigned long ToULong();

    long long ToLongLong();
    unsigned long long ToULongLong();

    float ToFloat();
    double ToDouble();

private:
    template <class T>
    T ToSomeType();
};

#endif
#ifndef ANYTYPE_HPP_SENTRY
#define ANYTYPE_HPP_SENTRY

class AnyType;
class UnTypedMPunsafe;
class UnTypedMP
{
    friend class AnyType;
    UnTypedMPunsafe *u;

public:
    UnTypedMP(int _size = 0);
    ~UnTypedMP();
    UnTypedMP &operator=(const UnTypedMP &a);

private:
    void *GetVar();
    int &GetSize();
};

class AnyType
{
    UnTypedMP *ptr;

public:
    AnyType();
    template <class T>
    AnyType(T a) : ptr(new UnTypedMP(sizeof(T)))
    {
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
};

#endif
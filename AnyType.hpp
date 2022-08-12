#ifndef ANYTYPE_HPP_SENTRY
#define ANYTYPE_HPP_SENTRY

class AnyType;
class UnTypedMPunsafe;
class UnTypedMP           // class where out object with size and
{                         // allocated memory will.
    friend class AnyType; // may be accessible for clients
    UnTypedMPunsafe *u;

public:
    UnTypedMP(int _size = 0);
    ~UnTypedMP();
    UnTypedMP &operator=(const UnTypedMP &a);

private:
    void *GetVar(); // access to our memory area and size;
    int &GetSize(); // accessible only for AnyType
};

class AnyType // main AnyType class
{
    UnTypedMP *ptr;

public:
    AnyType(); // default constructor
    template <class T>
    AnyType(T a) : ptr(new UnTypedMP(sizeof(T))) // conversion constructors
    {                                            // for types
        *(T *)ptr->GetVar() = a;
    }
    AnyType(const AnyType &a); // copy constructor
    ~AnyType();
    AnyType &operator=(const AnyType &a);

    void Destroy();        // destroy object
    void Swap(AnyType &a); // Swap 2 AnyTypes objects

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
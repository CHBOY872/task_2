#ifndef ANYTYPE_HPP_SENTRY
#define ANYTYPE_HPP_SENTRY

class AnyType;
class UnTypedMPunsafe
{
protected:
    friend class AnyType;
    void *var;
    int size;

public:
    UnTypedMPunsafe(int _size);
};

class UnTypedMP : private UnTypedMPunsafe
{
    friend class AnyType;

public:
    UnTypedMP(int _size = 0);
    ~UnTypedMP();
    UnTypedMP &operator=(const UnTypedMP &a);
};

class AnyType
{
    UnTypedMP *ptr;

public:
    AnyType();
    template <class T>
    AnyType(T a) : ptr(new UnTypedMP(sizeof(T)))
    {
        *(T *)ptr->var = a;
    }
    AnyType(const AnyType &a);
    ~AnyType();
    AnyType &operator=(const AnyType &a);

    void Destroy();
    void Swap(AnyType &a);
};

#endif
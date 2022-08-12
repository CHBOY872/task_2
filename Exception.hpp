#ifndef EXCEPTION_HPP_SENTRY
#define EXCEPTION_HPP_SENTRY

class ExceptionType // ExceptionType class
{
    int size_1;
    int size_2;
    char msg[256];

public:
    ExceptionType(int _size_1, int _size_2);
    ExceptionType(const ExceptionType &);

    char *GetMsg() { return msg; }
};

#endif
#ifndef EXCEPTION_HPP_SENTRY
#define EXCEPTION_HPP_SENTRY

class ExceptionType
{
    char msg[256];

public:
    ExceptionType();
    ExceptionType(const ExceptionType &);

    char *GetMsg() { return msg; }
};

#endif
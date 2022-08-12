#include "Exception.hpp"
#include <stdio.h>
#include <string.h>

ExceptionType::ExceptionType(int _size_1, int _size_2)
    : size_1(_size_1), size_2(_size_2)
{
    sprintf(msg, "Unsafe type cast exception: trying to convert a variable"
                 " with size %d to %d\n",
            size_1, size_2);
}
ExceptionType::ExceptionType(const ExceptionType &a)
{
    size_1 = a.size_1;
    size_2 = a.size_2;
    strcpy(msg, a.msg);
}
#include "Exception.hpp"
#include <stdio.h>  // for sprintf
#include <string.h> // for strcpy

ExceptionType::ExceptionType()
{
    sprintf(msg, "Unsafe type cast exception\n");
}
ExceptionType::ExceptionType(const ExceptionType &a)
{
    strcpy(msg, a.msg);
}
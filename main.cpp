#include <stdio.h> // for fprintf
#include "AnyType.hpp"
#include "Exception.hpp"

int main()
{
    try
    {
        int x;
        AnyType y = 90;
        y = false;
        x = y.ToBool();
    }
    catch (ExceptionType &a)
    {
        fprintf(stderr, "%s\n", a.GetMsg());
    }
    catch (...)
    {
        fprintf(stderr, "Unknown exception...\n");
    }

    return 0;
}
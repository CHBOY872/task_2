#include <stdio.h> // for fprintf
#include "AnyType.hpp"
#include "Exception.hpp"

int main()
{
    try
    {
        AnyType y = 90;
        AnyType x(y);
        x = 2.56;
        x = y.ToInt();
        int z = y.ToDouble();
        printf("%d\n", z);
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
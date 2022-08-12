#include "AnyType.hpp"
#include <iostream>
using namespace std;

int main()
{
    AnyType x(90);
    AnyType y = 1.53;
    y = x;
    x = y;
    AnyType c = x;
    AnyType d;
    d = c;
    d.Destroy();
    d = x;

    d.Swap(x);

    return 0;
}
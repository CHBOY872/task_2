#include <stdio.h> // for fprintf
#include <gtest/gtest.h>
#include "AnyType.hpp"
#include "Exception.hpp"

TEST(MainTest, Test)
{
    EXPECT_THROW({
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
        throw;
    }
    catch (...)
    {
        FAIL();
    }
    }, ExceptionType);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <stdio.h> // for fprintf
#include <gtest/gtest.h>
#include "AnyType/AnyType.hpp"
#include "Exception/Exception.hpp"

int main_func()
{
    try
    {
        AnyType x = 90;
        int y = x.ToInt();
        printf("%d\n", y);
    }
    catch (ExceptionType &a)
    {
        fprintf(stderr, "%s\n", a.GetMsg());
        throw;
    }
    catch (...)
    {
    }
    return 0;
}

TEST(MainTest, ThrowExceptionTest)
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
    },
                 ExceptionType);
}

TEST(MainTest, NoThrowExceptionTest)
{
    ASSERT_EQ(0, main_func());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

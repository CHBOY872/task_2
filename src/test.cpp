#include <stdio.h> // for fprintf
#include <gtest/gtest.h>
#include "AnyType/AnyType.hpp"
#include "Exception/Exception.hpp"

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
    EXPECT_THROW({
        try
        {
            AnyType x = 'A';
            int z = x.ToInt();
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
    EXPECT_THROW({
        try
        {
            AnyType x = 2.6f;
            double z = x.ToDouble();
            printf("%lf\n", z);
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
    EXPECT_NO_THROW({
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
            FAIL();
        }
    });
    EXPECT_NO_THROW({
        try
        {
            AnyType x = 2.5;
            x = 'x';
            char y = x.ToChar();
            printf("%c\n", y);
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
    });
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

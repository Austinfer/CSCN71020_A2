#include "pch.h"
#include "CppUnitTest.h"
extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(UnitTest1)
{
public:

    TEST_METHOD(TestGetPerimeter)
    {
        int length = 5;
        int width = 3;
        int expected = 16;
        int result = getPerimeter(&length, &width);
        Assert::AreEqual(expected, result);
    }
    TEST_METHOD(TestGetArea)
    {
        int length = 5;
        int width = 3;
        int expected = 15; 
        int result = getArea(&length, &width);
        Assert::AreEqual(expected, result);
    }
    TEST_METHOD(TestSetLengthValid)
    {
        int length = 0;
        setLength(10, &length);
        Assert::AreEqual(10, length);
    }

    TEST_METHOD(TestSetLengthInvalidLow)
    {
        int length = 5; 
        setLength(0, &length);
        Assert::AreEqual(5, length); 
    }

    TEST_METHOD(TestSetLengthInvalidHigh)
    {
        int length = 0;
        setLength(100, &length); 
        Assert::IsTrue(length != 100);
    }  TEST_METHOD(TestSetWidthValid)
    {
        int width = 0;
        setWidth(20, &width);
        Assert::AreEqual(20, width);
    }

    TEST_METHOD(TestSetWidthInvalidLow)
    {
        int width = 5;
        setWidth(0, &width);
        Assert::AreEqual(5, width);
    }

    TEST_METHOD(TestSetWidthInvalidHigh)
    {
        int width = 0;
        setWidth(100, &width);
        Assert::IsTrue(width != 100);
    }
};


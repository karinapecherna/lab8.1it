#define _CRT_SECURE_NO_WARNINGS 
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1/FileName.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestChangeFunction)
        {
            char input[101];
            strcpy_s(input, sizeof(input), "Hello OGO World!");

            
            char* result = Change(input);

            
            Assert::AreEqual("Hello ** World!", result);
        }
    };
}

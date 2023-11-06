#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.4.2/Lab 6.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
    TEST_CLASS(ArrayFunctionsTest)
    {
    public:
        TEST_METHOD(TestFindMaxIndex)
        {
            std::vector<int> arr = { 29, 15, 7, 42, 56, 18, 33, 12, 8, 45 };
            int maxIndex = 0;
            findMaxIndexRecursive(arr, maxIndex, 0);
            Assert::AreEqual(maxIndex, 4);
        }

        TEST_METHOD(TestProductBetweenZeros)
        {
            std::vector<int> arr = { 10, 35, 47, 0, 14, 6, 52, 0, 19, 5 };
            int product = 0;
            productBetweenZerosRecursive(arr, product, 0, -1, -1);
            Assert::AreEqual(product, 4368);
        }

        TEST_METHOD(TestProductBetweenZerosNoZeros)
        {
            std::vector<int> arr = { 1, 2, 3, 4, 5 };
            int product = 0;
            productBetweenZerosRecursive(arr, product, 0, -1, -1);
            Assert::AreEqual(product, 0);
        }
    };
}

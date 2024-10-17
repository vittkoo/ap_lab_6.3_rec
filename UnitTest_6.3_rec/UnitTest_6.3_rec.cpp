#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_lab_6.3_rec/lab_6.3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForArray
{
    TEST_CLASS(UnitTestForArray)
    {
    public:

        TEST_METHOD(TestCreateArray)
        {
            const int n = 5;
            int b[n];
            int Low = -10, High = 10;

            Create(b, n, Low, High, 0);

            for (int i = 0; i < n; i++) {
                Assert::IsTrue(b[i] >= Low && b[i] <= High);
            }
        }

        TEST_METHOD(TestMinOdd)
        {
            // 1. масив з непарними елементами
            const int n1 = 5;
            int a1[n1] = { 12, 7, 5, 20, 9 };
            int expectedMinOdd1 = 5;
            int minOdd;

            int actualMinOdd1 = MinOdd(a1, n1, minOdd, IFirst(a1, n1, minOdd, 0));
            Assert::AreEqual(expectedMinOdd1, actualMinOdd1);

            // 2. масив з одним непарним елементом
            const int n3 = 4;
            int a3[n3] = { 12, 14, 9, 22 };
            int expectedMinOdd3 = 9;

            int actualMinOdd3 = MinOdd(a3, n3, minOdd, IFirst(a3, n3, minOdd, 0));
            Assert::AreEqual(expectedMinOdd3, actualMinOdd3);
        }
    };
}

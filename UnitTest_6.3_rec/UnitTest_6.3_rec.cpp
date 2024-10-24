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

        TEST_METHOD(TestPrintArray)
        {
            const int n = 5;
            int a[n] = { 1, 2, 3, 4, 5 };
            Print(a, n, 0);
        }

        TEST_METHOD(TestMinOdd)
        {
            // 1. масив з непарними елементами
            const int n1 = 5;
            int a1[n1] = { 12, 7, 5, 20, 9 };
            int expectedMinOdd1 = 5;
            int minOdd1 = -1; // Ініціалізуємо змінну

            int actualMinOdd1 = MinOdd(a1, n1, minOdd1, IFirst(a1, n1, minOdd1, 0));
            Assert::AreEqual(expectedMinOdd1, actualMinOdd1);

            // 2. масив без непарних елементів
            const int n2 = 4;
            int a2[n2] = { 12, 22, 28, 46 };
            int expectedMinOdd2 = -1; // Змінено на -1 для більшої коректності
            int minOdd2 = -1; // Ініціалізуємо змінну

            int actualMinOdd2 = MinOdd(a2, n2, minOdd2, IFirst(a2, n2, minOdd2, 0));
            Assert::AreEqual(expectedMinOdd2, actualMinOdd2);

            // 3. масив з одним непарним елементом
            const int n3 = 4;
            int a3[n3] = { 12, 14, 9, 22 };
            int expectedMinOdd3 = 9;
            int minOdd3 = -1; // Ініціалізуємо змінну

            int actualMinOdd3 = MinOdd(a3, n3, minOdd3, IFirst(a3, n3, minOdd3, 0));
            Assert::AreEqual(expectedMinOdd3, actualMinOdd3);
        }

        TEST_METHOD(TestTemplateMinOdd)
        {
            const int n = 5;
            int a[n] = { 13, 24, 5, 8, 7 };
            int expectedMinOdd = 5;
            int minOdd = -1;

            // мінімальне непарне
            int actualMinOdd = MinOddTemplate(a, n, minOdd, 0);
            Assert::AreEqual(expectedMinOdd, actualMinOdd);

            // один непарний
            const int n2 = 4;
            int a2[n2] = { 2, 4, 6, 5 };
            expectedMinOdd = 5;

            actualMinOdd = MinOddTemplate(a2, n2, minOdd, 0);
            Assert::AreEqual(expectedMinOdd, actualMinOdd);

            // без непарних
            const int n3 = 4;
            int a3[n3] = { 2, 4, 6, 8 };
            expectedMinOdd = -1;

            actualMinOdd = MinOddTemplate(a3, n3, minOdd, 0);
            Assert::AreEqual(expectedMinOdd, actualMinOdd);
        }
    };
}

#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../OOP_Lab_3.1/Triad.cpp"
#include "../OOP_Lab_3.1/Time.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Lab31Tests
{
    TEST_CLASS(Lab31Tests)
    {
    public:

        // Тестування логіки порівняння тріад згідно варіанту 11
        TEST_METHOD(TriadComparisonLogicTest)
        {
            Triad t1(5, 5, 5);
            Triad t2(4, 9, 9);
            Triad t3(5, 6, 1);
            Triad t4(5, 5, 6);
            Triad t5(5, 5, 5);

            // (t1.first > t2.first) -> 5 > 4
            Assert::IsTrue(t1 > t2, L"Помилка: 5 > 4, тому t1 має бути більшим за t2");

            // (t1.first == t3.first) && (t3.second > t1.second) -> 5==5, 6>5
            Assert::IsTrue(t3 > t1, L"Помилка: 6 > 5, тому t3 має бути більшим за t1");

            // (t1.first == t4.first) && (t1.second == t4.second) && (t4.third > t1.third) -> 5==5, 5==5, 6>5
            Assert::IsTrue(t4 > t1, L"Помилка: 6 > 5 (third), тому t4 має бути більшим за t1");

            // Перевірка на хибність
            Assert::IsFalse(t1 > t5, L"Помилка: однакові тріади не можуть бути більшими одна за одну");
        }

        // Тестування ініціалізації та гетерів класу Time
        TEST_METHOD(TimeInitializationTest)
        {
            Time tm(14, 30, 45);

            Assert::AreEqual(14, tm.getFirst(), L"Години ініціалізовані неправильно");
            Assert::AreEqual(30, tm.getSecond(), L"Хвилини ініціалізовані неправильно");
            Assert::AreEqual(45, tm.getThird(), L"Секунди ініціалізовані неправильно");
        }

        // Тестування операторів порівняння часу
        TEST_METHOD(TimeOperatorsTest)
        {
            Time tm1(14, 30, 0);
            Time tm2(15, 0, 0);
            Time tm3(14, 30, 0);

            Assert::IsTrue(tm1 < tm2, L"14:30 має бути меншим за 15:00");
            Assert::IsTrue(tm2 > tm1, L"15:00 має бути більшим за 14:30");
            Assert::IsTrue(tm1 == tm3, L"Однакові об'єкти часу мають дорівнювати один одному");
            Assert::IsTrue(tm1 != tm2, L"Різні об'єкти часу не повинні дорівнювати один одному");

            Assert::IsTrue(tm1 <= tm3, L"Оператор <= працює некоректно");
            Assert::IsTrue(tm2 >= tm1, L"Оператор >= працює некоректно");
        }

        // Тестування перетворення до літерного рядку (форматування)
        TEST_METHOD(TimeToStringFormatTest)
        {
            Time tm(9, 5, 2);
            string expected = "09:05:02";
            string actual = (string)tm;

            Assert::AreEqual(expected, actual, L"Форматування часу в рядок працює некоректно (мають бути нулі попереду)");
        }
    };
}
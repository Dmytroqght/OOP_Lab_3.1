#include "Time.h"
#include <iostream>

using namespace std;

// Функція, що одержує і повертає об'єкти базового класу.
// Служить для демонстрації принципу підстановки і процесу розщеплення/зрізування.
Triad processTriad(Triad obj) {
    cout << "-> Function processTriad received a base class object: " << string(obj) << endl;
    obj.setFirst(obj.getFirst() + 1); // Зміна для тесту
    return obj;
}

int main() {
    cout << "=== Object Creation Demonstration ===" << endl;

    // Створення через конструктор за умовчанням
    Triad tr1;
    cout << "Triad tr1 (default): " << tr1 << endl;

    // Створення через конструктор ініціалізації
    Time tm1(14, 30, 45);
    cout << "Time tm1 (initialization): " << tm1 << endl;

    // Створення масиву об'єктів
    Time arr[3] = { Time(9, 15, 0), Time(12, 0, 0), Time(23, 59, 59) };
    cout << "\nArray of Time objects:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    cout << "\n=== Substitution Principle Demonstration ===" << endl;
    // Передаємо об'єкт похідного класу Time у функцію, яка чекає базовий клас Triad.
    Triad tr2 = processTriad(tm1);
    cout << "Result after returning from the function: " << tr2 << endl;

    cout << "\n=== Time Comparison Demonstration ===" << endl;
    Time tm2(15, 0, 0);
    cout << "tm1: " << tm1 << ", tm2: " << tm2 << endl;
    if (tm1 < tm2) cout << "tm1 is less than tm2 (earlier)" << endl;
    if (tm2 > tm1) cout << "tm2 is greater than tm1 (later)" << endl;
    if (tm1 != tm2) cout << "tm1 is not equal to tm2" << endl;

    cout << "\n=== Input Validation Demonstration ===" << endl;
    cout << "Enter the time:" << endl;
    Time tm3;
    cin >> tm3; // Якщо ввести, наприклад, 25 для годин, програма виведе помилку і завершиться
    cout << "You entered: " << tm3 << endl;

    return 0;
}
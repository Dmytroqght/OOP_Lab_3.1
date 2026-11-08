#pragma once
#include <iostream>
#include <string>

using namespace std;

class Triad {
private:
    int first, second, third;

public:
    // Конструктори
    Triad(const int f = 0, const int s = 0, const int t = 0);
    Triad(const Triad& r);
    virtual ~Triad(void);

    // Методи отримання значень (гетери)
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    int getThird() const { return third; }

    // Методи встановлення значень (сетери). 
    // Робимо їх віртуальними, щоб у похідному класі реалізувати жорсткий контроль.
    virtual void setFirst(const int f);
    virtual void setSecond(const int s);
    virtual void setThird(const int t);

    // Метод порівняння тріад згідно умови завдання
    bool operator > (const Triad& t2) const;

    // Перетворення до літерного рядку
    virtual operator string() const;

    // Операції вводу / виводу
    friend ostream& operator << (ostream& out, const Triad& r);
    friend istream& operator >> (istream& in, Triad& r);
};
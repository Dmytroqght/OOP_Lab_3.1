#pragma once
#include "Triad.h"

class Time : public Triad {
public:
    // Конструктори
    Time(const int h = 0, const int m = 0, const int s = 0);
    Time(const Time& r);
    ~Time(void);

    // Перевизначені методи встановлення для суворого контролю значень часу
    void setFirst(const int h) override;
    void setSecond(const int m) override;
    void setThird(const int s) override;

    // Повний набір методів порівняння моментів часу
    friend bool operator == (const Time& t1, const Time& t2);
    friend bool operator != (const Time& t1, const Time& t2);
    friend bool operator >  (const Time& t1, const Time& t2);
    friend bool operator <  (const Time& t1, const Time& t2);
    friend bool operator >= (const Time& t1, const Time& t2);
    friend bool operator <= (const Time& t1, const Time& t2);

    // Перетворення до літерного рядку
    operator string() const override;

    // Операції вводу / виводу для нового формату
    friend ostream& operator << (ostream& out, const Time& r);
    friend istream& operator >> (istream& in, Time& r);
};
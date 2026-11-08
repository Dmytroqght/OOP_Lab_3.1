#include "Time.h"
#include <sstream>
#include <iomanip>
#include <cstdlib> // для виклику exit()

// Конструктор: безпека гарантована викликом віртуальних сетерів
Time::Time(const int h, const int m, const int s) : Triad() {
    setFirst(h);
    setSecond(m);
    setThird(s);
}

Time::Time(const Time& r) : Triad(r) {}

Time::~Time(void) {}

// Сетер з жорсткою перевіркою коректності годин
void Time::setFirst(const int h) {
    if (h < 0 || h > 23) {
        cerr << "Помилка: Неприпустиме значення для годин (0-23)!" << endl;
        exit(1); // Завершення роботи при невірних даних
    }
    Triad::setFirst(h);
}

// Сетер з жорсткою перевіркою коректності хвилин
void Time::setSecond(const int m) {
    if (m < 0 || m > 59) {
        cerr << "Помилка: Неприпустиме значення для хвилин (0-59)!" << endl;
        exit(1);
    }
    Triad::setSecond(m);
}

// Сетер з жорсткою перевіркою коректності секунд
void Time::setThird(const int s) {
    if (s < 0 || s > 59) {
        cerr << "Помилка: Неприпустиме значення для секунд (0-59)!" << endl;
        exit(1);
    }
    Triad::setThird(s);
}

bool operator == (const Time& t1, const Time& t2) {
    return (t1.getFirst() == t2.getFirst() &&
        t1.getSecond() == t2.getSecond() &&
        t1.getThird() == t2.getThird());
}

bool operator != (const Time& t1, const Time& t2) {
    return !(t1 == t2);
}

bool operator > (const Time& t1, const Time& t2) {
    // Використовуємо метод порівняння базового класу Triad
    return (const Triad&)t1 > (const Triad&)t2;
}

bool operator < (const Time& t1, const Time& t2) {
    return t2 > t1;
}

bool operator >= (const Time& t1, const Time& t2) {
    return (t1 > t2) || (t1 == t2);
}

bool operator <= (const Time& t1, const Time& t2) {
    return (t1 < t2) || (t1 == t2);
}

Time::operator string() const {
    stringstream ss;
    ss << setfill('0') << setw(2) << getFirst() << ":"
        << setfill('0') << setw(2) << getSecond() << ":"
        << setfill('0') << setw(2) << getThird();
    return ss.str();
}

ostream& operator << (ostream& out, const Time& r) {
    return out << (string)r;
}

istream& operator >> (istream& in, Time& r) {
    int h, m, s;
    cout << "hours = "; in >> h;
    cout << "minutes = "; in >> m;
    cout << "seconds = "; in >> s;
    r.setFirst(h);
    r.setSecond(m);
    r.setThird(s);
    return in;
}
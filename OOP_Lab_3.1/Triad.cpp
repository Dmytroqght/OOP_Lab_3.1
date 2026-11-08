#include "Triad.h"
#include <sstream>

// Конструктор ініціалізації та за умовчанням
Triad::Triad(const int f, const int s, const int t) {
    setFirst(f);
    setSecond(s);
    setThird(t);
}

// Конструктор копіювання
Triad::Triad(const Triad& r) {
    first = r.first;
    second = r.second;
    third = r.third;
}

Triad::~Triad(void) {}

void Triad::setFirst(const int f) {
    first = f;
}

void Triad::setSecond(const int s) {
    second = s;
}

void Triad::setThird(const int t) {
    third = t;
}

// Перевантаження операції порівняння згідно варіанту 11
bool Triad::operator > (const Triad& t2) const {
    if (first > t2.first) {
        return true;
    }
    if ((first == t2.first) && (second > t2.second)) {
        return true;
    }
    if ((first == t2.first) && (second == t2.second) && (third > t2.third)) {
        return true;
    }
    return false;
}

// Перетворення до літерного рядку
Triad::operator string() const {
    stringstream ss;
    ss << "(" << first << ", " << second << ", " << third << ")";
    return ss.str();
}

ostream& operator << (ostream& out, const Triad& r) {
    return out << (string)r;
}

istream& operator >> (istream& in, Triad& r) {
    int f, s, t;
    cout << "first = "; in >> f;
    cout << "second = "; in >> s;
    cout << "third = "; in >> t;
    r.setFirst(f);
    r.setSecond(s);
    r.setThird(t);
    return in;
}
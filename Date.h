#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    int day;
    int month;
    int year;

    Date();
    std::string ToString() const;
    void FromString(const std::string &str);
    void SetCurrent();
};

#endif
#include "Date.h"
#include <cstring>
#include <windows.h>

using namespace std;

Date::Date() {
    SetCurrent();
}

string Date::ToString() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

void Date::FromString(const string& str) {
    char s[64];
    strcpy(s, str.c_str());

    char *tkn = strtok(s, "/");
    day = atoi(tkn);
    tkn = strtok(nullptr, "/");
    month = atoi(tkn);
    tkn = strtok(nullptr, "/");
    year = atoi(tkn);
}

void Date::SetCurrent() {
    SYSTEMTIME time;
    GetSystemTime(&time);
    day   = time.wDay;
    month = time.wMonth;
    year  = time.wYear;
}

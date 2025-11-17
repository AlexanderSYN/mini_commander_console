//
// Created by AlexanderSYN on 18.11.2025.
//

#ifndef DATE_AND_DATE_H
#define DATE_AND_DATE_H

#ifdef _IOSTREAM_
    #define IOSTREAM_INCLUDED 1
#else
    #include <iostream>
    #define IOSTREAM_INCLUDED 0
#endif

#include <ctime>

struct time {
    int tm_sec;   // seconds of minutes from 0 to 61
    int tm_min;   // minutes of hour from 0 to 59
    int tm_hour;  // hours of day from 0 to 24
    int tm_mday;  // day of month from 1 to 31
    int tm_mon;   // month of year from 0 to 11
    int tm_year;  // year since 1900
    int tm_wday;  // days since sunday
    int tm_yday;  // days since January 1st
    int tm_isdst; // hours of daylight savings time
};

class time_and_date {

public:
    static void output_time();

    static void output_local_date_and_time();

};

#endif //DATE_AND_TIME_H

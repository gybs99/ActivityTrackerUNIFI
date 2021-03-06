//
// Created by redi on 12/03/21.
//

#include "Date.h"

Date::Date() {

    time_t systemTime = time(nullptr);
    currentTime = localtime(&systemTime);

    day = currentTime -> tm_mday;
    month = currentTime -> tm_mon + 1;
    year = currentTime -> tm_year + 1900;

    if (checkDateFormat())
        throw WrongTimeFormatException();

}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

bool Date::checkDateFormat() const {

    if ((year < 1900) || (year > 9999))        // It will be assumed that a managed date is greater than 1900 and don't reach more than 9999
        return true;

    if ((month < 1) || (month > 12))
        return true;

    if (day < 1)
        return true;

    if ((year % 100 == 0) && ((year % 400 == 0)))           // Check if the year chosen is leap, looking if it's a secular year and divisible for 400
        if ((month == 2) && (day > 29))
            return true;

    if ((year % 100 != 0) && (year % 4 == 0))       // Check if the year chosen is leap, looking if it isn't a secular year and divisible for 4
        if ((month == 2) && (day > 29))
            return true;

    if ((month == 2) && (day > 28))
        return true;


    if(month % 2 == 0) {                    // Check if any month take the right maximum number of days
        if ((month <= 6) && (day > 30))
            return true;
        else {
            if (day > 31)
                return true;
        }
    }
    else
        if ((month <= 7) && (day > 31))
            return true;
        else {
            if (day > 30)
            return true;
        }

    return false;

}

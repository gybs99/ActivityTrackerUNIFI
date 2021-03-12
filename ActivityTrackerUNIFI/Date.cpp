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

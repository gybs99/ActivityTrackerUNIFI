//
// Created by redi on 12/03/21.
//

#ifndef ACTIVITYTRACKERUNIFI_DATE_H
#define ACTIVITYTRACKERUNIFI_DATE_H
#include <ctime>
#include <memory>

class Date {

public:

    Date();
    int getDay() const;
    int getMonth() const;
    int getYear() const;


private:

    int day;
    int month;
    int year;
    tm* currentTime;

};


#endif //ACTIVITYTRACKERUNIFI_DATE_H

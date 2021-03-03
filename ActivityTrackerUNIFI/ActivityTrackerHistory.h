//
// Created by redi on 01/03/21.
//
#include "DailyActivityRegister.h"


#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERHISTORY_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERHISTORY_H


class ActivityTrackerHistory {                  // This particular class doesn't implement Observer pattern. This because

public:

    ActivityTrackerHistory();

    void addRegister(std::shared_ptr<DailyActivityRegister>& newRegister);

    void removeRegister(std::shared_ptr<DailyActivityRegister>& toDelete);

    std::shared_ptr<DailyActivityRegister> searchTodayRegister();

    std::shared_ptr<DailyActivityRegister> searchRegister(int day, int month, int year);

    const std::list<std::shared_ptr<DailyActivityRegister>> &getHistory() const;

    std::shared_ptr<DailyActivityRegister> getSelectedRegister(const std::string& registerDate);


private:

    std::list<std::shared_ptr<DailyActivityRegister>> history;    // The history of the program is based on a collection of daily registers. Each one contains
                                                                  // each one contains activities done in a particular day
    time_t systemTime;
    struct tm* currentDate;

};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERHISTORY_H

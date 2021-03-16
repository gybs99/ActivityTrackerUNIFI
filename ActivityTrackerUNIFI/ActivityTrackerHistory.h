//
// Created by redi on 01/03/21.
//
#include "DailyActivityRegister.h"


#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERHISTORY_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERHISTORY_H


class ActivityTrackerHistory {                  // This particular class doesn't implement Observer pattern. This because it has not to be updated
                                                // when his related view is opened
public:

    ActivityTrackerHistory();

    void addRegister(std::shared_ptr<DailyActivityRegister>& newRegister);

    void removeRegister(std::shared_ptr<DailyActivityRegister>& toDelete);

    std::shared_ptr<DailyActivityRegister> searchTodayRegister();

    std::shared_ptr<DailyActivityRegister> searchRegister(int day, int month, int year);

    std::shared_ptr<DailyActivityRegister>& searchRegister(int registerPos);

    std::shared_ptr<DailyActivityRegister> getSelectedRegister(const std::string& registerDate);

    bool isHistoryEmpty();

    int getHistoryDimension();


private:

    std::list<std::shared_ptr<DailyActivityRegister>> history;    // The history of the program is based on a collection of daily registers. Each one contains
                                                                  // each one contains activities done in a particular day


    time_t systemTime;                  // These system time's structures are needed for searching the today register
    struct tm* currentDate;

};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERHISTORY_H

//
// Created by redi on 22/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H
#define ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

#include <ctime>
#include <map>
#include <iostream>

#include "Activity.h"

struct Date
{
    int day;
    int month;
    int year;
};

class DailyActivityRegister : public Subject {

public:

    DailyActivityRegister();

    ~DailyActivityRegister() override;

    DailyActivityRegister(DailyActivityRegister&) = delete;

    DailyActivityRegister& operator= (const DailyActivityRegister) = delete;

    void subscribeView(Observer *newView) override;

    void unsubscribeView(Observer *removedView) override;

    void notifyChange() override;

    void addNewActivity(std::shared_ptr<Activity> newActivity);

    void removeActivity(const std::shared_ptr<Activity>& selectedActivity);

    const std::map<int, std::shared_ptr<Activity>> &getListOfActivity() const;

    Date *getDate() const;


private:

    std::map<int,std::shared_ptr<Activity>> listOfActivity;
    Date* date {nullptr};
    struct tm* currentTime;
    std::list<Observer*> registerViews {nullptr};
    int activityID = 0;

};


#endif //ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

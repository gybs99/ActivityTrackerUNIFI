//
// Created by redi on 22/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H
#define ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

#include <ctime>
#include <map>
#include <iostream>
#include "Date.h"
#include "Activity.h"


class DailyActivityRegister : public Subject {

public:

    void subscribeView(Observer *newView) override;

    void unsubscribeView(Observer *removedView) override;

    void notifyChange() override;

    void addNewActivity(std::shared_ptr<Activity> newActivity);

    void removeActivity(const std::shared_ptr<Activity>& selectedActivity);

    const std::map<int, std::shared_ptr<Activity>> &getListOfActivity() const;

    const Date &getRegisterDate() const;

private:

    std::map<int,std::shared_ptr<Activity>> listOfActivity;
    struct tm* currentTime;
    std::list<Observer*> registerViews {nullptr};
    int activityID = 0;
    Date registerDate;

};


#endif //ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

//
// Created by redi on 22/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H
#define ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

#include <ctime>
#include <vector>
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

    std::shared_ptr<Activity>& findActivity(int activitySelected);

    const Date &getRegisterDate() const;

    bool isListOfActivityEmpty();

    int getNumberOfActivity();

private:

    std::vector<std::shared_ptr<Activity>> listOfActivity;
    tm* currentTime;
    std::list<Observer*> registerViews {nullptr};
    Date registerDate;

};


#endif //ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

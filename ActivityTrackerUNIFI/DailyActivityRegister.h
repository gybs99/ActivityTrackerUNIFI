//
// Created by redi on 22/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H
#define ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

#include <ctime>
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

    void subscribeView(Observer *newView) override;

    void unsubscribeView(Observer *removedView) override;

    void notifyChange() override;

    void addNewActivity(std::shared_ptr<Activity> newActivity);

private:

    std::list<std::shared_ptr<Activity>> listOfActivity {nullptr};
    Date* date {nullptr};
    struct tm* currentTime;
    std::list<Observer*> registerViews {nullptr};

};


#endif //ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTER_H

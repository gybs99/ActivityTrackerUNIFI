//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITY_H
#define ACTIVITYTRACKERUNIFI_ACTIVITY_H


#include <string>
#include <list>
#include "Subject.h"
#include "ActivityTime.h"


class Activity : public Subject {

public:

    Activity(std::string newType, std::string newDescription, ActivityTime newTime);

    void subscribeView(Observer *newView) override;

    void unsubscribeView(Observer *removedView) override;

    void notifyChange() override;

    const std::string &getDescription() const;

    const std::string &getType() const;

    void setType(const std::string &newType);

    void modifyInfo(std::string newType, std::string newDescription);

    const ActivityTime &getDateAndDuration() const;

private:

    std::string description;
    ActivityTime dateAndDuration;
    std::string type;
    std::list<Observer*> activityViews;
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITY_H

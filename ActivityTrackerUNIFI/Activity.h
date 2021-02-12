//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITY_H
#define ACTIVITYTRACKERUNIFI_ACTIVITY_H


#include <string>
#include <ctime>
#include <list>
#include "Subject.h"

class Activity : public Subject {

public:
    Activity(const std::string newType, const std::string newDescription, int startingMin, int startingHour,
             int finishingMin, int finishingHour);

    const std::string &getType() const;

    virtual ~Activity();

    void setType(const std::string &type);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    void subscribeView(Observer *newView) override;

    void unsubscribeView(Observer *removedView) override;

    void notifyChange() override;

private:
    std::string type;
    std::string description;
    struct tm* startingTime;
    struct tm* finishingTime;

    std::list<Observer*> activityViews;
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITY_H

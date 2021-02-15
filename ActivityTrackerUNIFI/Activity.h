//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITY_H
#define ACTIVITYTRACKERUNIFI_ACTIVITY_H


#include <string>
#include <ctime>
#include <list>
#include "Subject.h"

struct startFinishTime
{
    int startingMin;
    int startingHour;
    int finishingMin;
    int finishingHour;
    int day;
    int month;
    int year;
};

class Activity : public Subject {

public:
    Activity(const std::string& newType, const std::string& newDescription, int startingMin, int startingHour,
             int finishingMin, int finishingHour);

    ~Activity() override;

    void subscribeView(Observer *newView) override;

    void unsubscribeView(Observer *removedView) override;

    void notifyChange() override;

    void setStartFinishTime(int startingMin, int startingHour, int finishingMin, int finishingHour);

    startFinishTime *getTimeSet() const;

    void setTimeSet(startFinishTime *timeSet);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getType() const;

    void setType(const std::string &type);

private:

    std::string description;
    struct tm* Date;
    std::string type;
    struct startFinishTime* timeSet {nullptr};
    std::list<Observer*> activityViews;
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITY_H

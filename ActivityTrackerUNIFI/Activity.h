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
    std::string startingMin;
    std::string startingHour;
    std::string finishingMin;
    std::string finishingHour;
    int day;
    int month;
    int year;
};

class Activity : public Subject {

public:
    Activity(std::string newType, std::string newDescription, std::string startingMin, std::string startingHour,
             std::string finishingMin, std::string finishingHour);

    ~Activity() override;

    void subscribeView(Observer *newView) override;

    void unsubscribeView(Observer *removedView) override;

    void notifyChange() override;

    void setStartFinishTime(std::string startingMin, std::string startingHour, std::string finishingMin, std::string finishingHour);

    startFinishTime *getTimeSet() const;

    void setTimeSet(startFinishTime *newTimeSet);

    const std::string &getDescription() const;

    void setDescription(const std::string &newDescription);

    const std::string &getType() const;

    void setType(const std::string &newType);

    void modifyInfo(std::string newType, std::string newDescription, std::string startingMin, std::string startingHour,
                    std::string finishingMin, std::string finishingHour);

private:

    std::string description;
    struct tm* Date;
    std::string type;
    struct startFinishTime* timeSet {nullptr};
    std::list<Observer*> activityViews;
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITY_H

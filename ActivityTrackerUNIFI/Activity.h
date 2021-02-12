//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITY_H
#define ACTIVITYTRACKERUNIFI_ACTIVITY_H


#include <string>
#include <ctime>

class Activity {

public:
    Activity(std::string type, std::string description, int startingMin, int startingHour,
             int finishingMin, int finishingHour);

    const std::string &getType() const;

    virtual ~Activity();

    void setType(const std::string &type);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

private:
    std::string type;
    std::string description;
    struct tm* startingTime;
    struct tm* finishingTime;
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITY_H

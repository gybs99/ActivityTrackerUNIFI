//
// Created by redi on 12/03/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTIME_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTIME_H
#include "Date.h"

class ActivityTime : public Date {

public:

    ActivityTime(std::string newStartingMin, std::string newStartingHour,
                 std::string newFinishingMin, std::string newFinishingHour);

    ActivityTime& operator=(const ActivityTime& toCopy) = default;

    int checkTimeFormat();

    const std::string &getStartingMin() const;

    const std::string &getStartingHour() const;

    const std::string &getFinishingMin() const;

    const std::string &getFinishingHour() const;

private:

    std::string startingMin;
    std::string startingHour;
    std::string finishingMin;
    std::string finishingHour;

};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTIME_H

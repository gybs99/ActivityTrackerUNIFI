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

    const std::string &getStartingMin() const;

    void setStartingMin(const std::string &startingMin);

    const std::string &getStartingHour() const;

    void setStartingHour(const std::string &startingHour);

    const std::string &getFinishingMin() const;

    void setFinishingMin(const std::string &finishingMin);

    const std::string &getFinishingHour() const;

    void setFinishingHour(const std::string &finishingHour);

private:

    std::string startingMin;
    std::string startingHour;
    std::string finishingMin;
    std::string finishingHour;

};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTIME_H

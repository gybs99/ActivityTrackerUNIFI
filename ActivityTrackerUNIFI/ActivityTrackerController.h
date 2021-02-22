//
// Created by redi on 19/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H
#include "Activity.h"
#include "ActivityView.h"
#include "DailyActivityRegister.h"


class ActivityTrackerController {

public:
    ActivityTrackerController() = default;
    void createActivity(std::string newType, std::string newDescription, std::string startingMin,
                        std::string startingHour, std::string finishingMin, std::string finishingHour);

private:

    std::shared_ptr<Activity> managedActivity {nullptr};
    std::shared_ptr<DailyActivityRegister> todayRegister {nullptr};

};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H

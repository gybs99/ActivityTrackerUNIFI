//
// Created by redi on 19/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H
#include "Activity.h"
#include "ActivityView.h"


class ActivityTrackerController {

public:
    ActivityTrackerController();
    void createActivity(std::string &newType, std::string &newDescription, int startingMin,
                        int startingHour, int finishingMin, int finishingHour);

private:
    std::shared_ptr<Activity> managedActivity {nullptr};
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H

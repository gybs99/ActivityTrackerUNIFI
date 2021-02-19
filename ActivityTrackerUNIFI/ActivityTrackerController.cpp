//
// Created by redi on 19/02/21.
//

#include "ActivityTrackerController.h"

ActivityTrackerController::ActivityTrackerController() {

}

void ActivityTrackerController::createActivity(std::string &newType, std::string &newDescription, int startingMin,
                                               int startingHour, int finishingMin, int finishingHour) {

    managedActivity = std::make_shared<Activity>(newType, newDescription, 10, 10, 10, 10);
    ActivityView* newActivityView = new ActivityView(managedActivity);
    newActivityView -> Show();

}

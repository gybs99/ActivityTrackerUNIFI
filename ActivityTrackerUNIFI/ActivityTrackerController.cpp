//
// Created by redi on 19/02/21.
//

#include "ActivityTrackerController.h"


void ActivityTrackerController::createActivity(std::string newType, std::string newDescription, std::string startingMin,
                                               std::string startingHour, std::string finishingMin, std::string finishingHour) {

    managedActivity = std::make_shared<Activity>(std::move(newType), std::move(newDescription), std::move(startingMin),
                                                 std::move(startingHour), std::move(finishingMin), std::move(finishingHour));

    if (!todayRegister)
        todayRegister = std::make_shared<DailyActivityRegister>();
    todayRegister -> addNewActivity(managedActivity);

    auto addActivityView = new ActivityView(managedActivity);
    addActivityView -> Show();

}

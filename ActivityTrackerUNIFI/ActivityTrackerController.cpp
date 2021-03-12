//
// Created by redi on 19/02/21.
//

#include "ActivityTrackerController.h"


ActivityTrackerController::ActivityTrackerController(std::shared_ptr<ActivityTrackerHistory> loadingHistory) : loadedHistory(std::move(loadingHistory)){

    todayRegister = loadedHistory -> searchTodayRegister();

}

void ActivityTrackerController::createActivity(std::string newType, std::string newDescription, ActivityTime newTime) {

    managedActivity = std::make_shared<Activity>(std::move(newType), std::move(newDescription), std::move(newTime));

    if (!todayRegister) {

        todayRegister = std::make_shared<DailyActivityRegister>();          // If the activity is the first of the current day, a new reigster
        loadedHistory -> addRegister(todayRegister);                     // will be created

    }

    todayRegister -> addNewActivity(managedActivity);
    todayRegister -> notifyChange();

}

const std::shared_ptr<DailyActivityRegister> &ActivityTrackerController::getTodayRegister() const {
    return todayRegister;
}

const std::shared_ptr<Activity> &ActivityTrackerController::getActivitySelected(int activitySelected) {
    return todayRegister -> getListOfActivity().find(activitySelected) -> second;
}

void ActivityTrackerController::removeActivity(std::shared_ptr<Activity>& selectedActivity) {
    todayRegister -> removeActivity(selectedActivity);
}

void ActivityTrackerController::modifyActivity(std::shared_ptr<Activity> &selectedActivity, std::string newType, std::string newDescription, std::string newStartingMin,
                                               std::string newStartingHour, std::string newFinishingMin, std::string newFinishingHour) {

    selectedActivity -> modifyInfo(std::move(newType), std::move(newDescription), std::move(newStartingMin), std::move(newStartingHour),
                                   std::move(newFinishingMin), std::move(newFinishingHour));

    todayRegister -> notifyChange();

}

const std::shared_ptr<Activity> &ActivityTrackerController::getManagedActivity() const {
    return managedActivity;
}

const std::shared_ptr<ActivityTrackerHistory> &ActivityTrackerController::getLoadedHistory() const {
    return loadedHistory;
}

std::shared_ptr<DailyActivityRegister> ActivityTrackerController::getRegisterSelected(std::string date) {
    return loadedHistory -> getSelectedRegister(date);
}

void ActivityTrackerController::removeRegister() {
    loadedHistory -> removeRegister(todayRegister);               // if a register has no more activities and his view has been closed
    todayRegister = nullptr;                                         // it will be deleted from the history
}


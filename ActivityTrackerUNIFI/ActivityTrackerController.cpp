//
// Created by redi on 19/02/21.
//

#include "ActivityTrackerController.h"


ActivityTrackerController::ActivityTrackerController(std::shared_ptr<ActivityTrackerHistory> loadingHistory) : loadedHistory(std::move(loadingHistory)){

    todayRegister = loadedHistory -> searchTodayRegister();

}

int ActivityTrackerController::createActivity(std::string newType, std::string newDescription, const ActivityTime& newTime) {

    try {

        managedActivity = std::make_shared<Activity>(std::move(newType), std::move(newDescription), newTime);

        if (!todayRegister) {

            todayRegister = std::make_shared<DailyActivityRegister>();          // If the activity is the first of the current day, a new register
            loadedHistory->addRegister(todayRegister);                     // will be created

        }

        todayRegister->addNewActivity(managedActivity);
        todayRegister->notifyChange();
        return 0;
    }

    catch (WrongTimeFormatException& timeError) {
        std::cout << "Register Date format is not valid!";
        return 1;
    }

}

const std::shared_ptr<DailyActivityRegister> &ActivityTrackerController::getTodayRegister() const {
    return todayRegister;
}

std::shared_ptr<Activity> ActivityTrackerController::getActivitySelected(int activitySelected) {
    return todayRegister -> findActivity(activitySelected);
}

bool ActivityTrackerController::removeActivity(const std::shared_ptr<Activity>& selectedActivity) {
    return todayRegister -> removeActivity(selectedActivity);
}

void ActivityTrackerController::modifyActivity(std::shared_ptr<Activity> &selectedActivity, std::string newType, std::string newDescription,
                                               const ActivityTime& newTime) {

    const_cast<ActivityTime &>(selectedActivity->getDateAndDuration()) = newTime;

    selectedActivity -> modifyInfo(std::move(newType), std::move(newDescription));

    todayRegister -> notifyChange();

}

const std::shared_ptr<Activity> &ActivityTrackerController::getManagedActivity() const {
    return managedActivity;
}

std::shared_ptr<DailyActivityRegister> ActivityTrackerController::getRegisterSelected(const std::string& date) {
    return loadedHistory -> getSelectedRegister(date);
}

void ActivityTrackerController::removeRegister() {
    loadedHistory -> removeRegister(todayRegister);               // if a register has no more activities and his view has been closed
    todayRegister = nullptr;                                         // it will be deleted from the history
}

bool ActivityTrackerController::isHistoryEmpty() {
    return loadedHistory -> isHistoryEmpty();
}

int ActivityTrackerController::getHistoryDimension() {
    return loadedHistory -> getHistoryDimension();
}

std::shared_ptr<DailyActivityRegister> ActivityTrackerController::getRegisterSelected(int registerPos) {
    return loadedHistory -> searchRegister(registerPos);
}

std::shared_ptr<DailyActivityRegister> ActivityTrackerController::searchRegister(int day, int month, int year) {
    return loadedHistory -> searchRegister(day, month, year);
}


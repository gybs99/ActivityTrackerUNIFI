//
// Created by redi on 22/02/21.
//

#include "DailyActivityRegister.h"

DailyActivityRegister::DailyActivityRegister() {

    time_t systemTime = time(nullptr);
    currentTime = localtime(&systemTime);

    date = new Date;

    date -> day = currentTime -> tm_mday;
    date -> month = currentTime -> tm_mon + 1;
    date -> year = currentTime -> tm_year + 1900;

}

void DailyActivityRegister::subscribeView(Observer *newView) {
    registerViews.push_back(newView);
}

void DailyActivityRegister::unsubscribeView(Observer *removedView) {
    registerViews.remove(removedView);
}

void DailyActivityRegister::addNewActivity(std::shared_ptr<Activity> newActivity) {
    listOfActivity.push_back(std::move(newActivity));
}

void DailyActivityRegister::notifyChange() {

}

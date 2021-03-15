//
// Created by redi on 22/02/21.
//

#include <map>
#include "DailyActivityRegister.h"

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

    if (!registerViews.empty())
        for (auto itr : registerViews) {
            if (itr)
                itr -> updateView();
        }

}



void DailyActivityRegister::removeActivity(const std::shared_ptr<Activity>& selectedActivity) {

    bool found = false;
    auto itr = listOfActivity.begin();

    while (!found)
    {
        if ( (*itr) == selectedActivity)
        {
            listOfActivity.erase(itr);
            found = true;
        }
        else itr++;

    }
    notifyChange();
}

const Date &DailyActivityRegister::getRegisterDate() const {
    return registerDate;
}

std::shared_ptr<Activity>& DailyActivityRegister::findActivity(int activitySelected) {
    return listOfActivity[activitySelected];
}

bool DailyActivityRegister::isListOfActivityEmpty() {
    return listOfActivity.empty();
}

int DailyActivityRegister::getNumberOfActivity() {
    return listOfActivity.size();
}

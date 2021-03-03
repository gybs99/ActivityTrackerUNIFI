//
// Created by redi on 22/02/21.
//

#include <map>
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

    listOfActivity.insert(std::make_pair(activityID, std::move(newActivity)));
    activityID++;

}

void DailyActivityRegister::notifyChange() {

    if (!registerViews.empty())
        for (auto itr : registerViews) {
            if (itr)
                itr -> updateView();
        }


}

const std::map<int, std::shared_ptr<Activity>> &DailyActivityRegister::getListOfActivity() const {
    return listOfActivity;
}

void DailyActivityRegister::removeActivity(const std::shared_ptr<Activity>& selectedActivity) {

    bool found = false;
    auto itr = listOfActivity.begin();
    int activityIDtoDelete;

    while (!found)
    {
        if ( itr -> second == selectedActivity)
        {
            activityIDtoDelete = itr -> first;
            found = true;
        } else itr++;

    }

    listOfActivity.erase(activityIDtoDelete);

    activityID = 0;
    std::list<std::shared_ptr<Activity>> supportList;

    for (const auto& itr1 : listOfActivity) {
        supportList.push_back(itr1.second);
    }

    auto itr2 = listOfActivity.begin();
    auto itr3 = listOfActivity.end();

    listOfActivity.erase(itr2,itr3);

    for (const auto& itr4 : supportList)
    {
        listOfActivity.insert(std::make_pair(activityID, itr4));
        activityID++;
    }

    notifyChange();
}

DailyActivityRegister::~DailyActivityRegister() {
    delete date;
}

Date *DailyActivityRegister::getDate() const {
    return date;
}

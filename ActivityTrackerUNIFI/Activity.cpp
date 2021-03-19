//
// Created by redi on 12/02/21.
//

#include "Activity.h"

Activity::Activity(std::string newType, std::string newDescription, const ActivityTime& newTime) : type(std::move(newType)), description(std::move(newDescription)),
                    dateAndDuration(newTime) {
}

void Activity::subscribeView(Observer *newView) {
    activityViews.push_back(newView);
}

void Activity::unsubscribeView(Observer *removedView) {
    activityViews.remove(removedView);
}

void Activity::notifyChange() {

    if (!activityViews.empty())
    for(auto view : activityViews)
        view -> updateView();

}

const std::string &Activity::getDescription() const {
    return description;
}

const std::string &Activity::getType() const {
    return type;
}

void Activity::setType(const std::string &newType) {
    Activity::type = newType;
}

void Activity::modifyInfo(std::string newType, std::string newDescription) {

    type = std::move(newType);
    description = std::move(newDescription);
    notifyChange();

}

const ActivityTime &Activity::getDateAndDuration() const {
    return dateAndDuration;
}

int Activity::getNumberOfViews() {
    return activityViews.size();
}





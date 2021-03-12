//
// Created by redi on 12/02/21.
//

#include "Activity.h"

Activity::Activity(std::string newType, std::string newDescription, ActivityTime newTime) : type(std::move(newType)), description(std::move(newDescription)),
                    dateAndDuration(std::move(newTime)) {

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

void Activity::modifyInfo(std::string newType, std::string newDescription, std::string newStartingMin, std::string newStartingHour,
                          std::string newFinishingMin, std::string newFinishingHour) {

    type = std::move(newType);
    description = std::move(newDescription);

    dateAndDuration.setStartingMin(newStartingMin);
    dateAndDuration.setStartingHour(newStartingHour);
    dateAndDuration.setFinishingMin(newFinishingMin);
    dateAndDuration.setFinishingHour(newFinishingHour);

    notifyChange();

}

const ActivityTime &Activity::getDateAndDuration() const {
    return dateAndDuration;
}





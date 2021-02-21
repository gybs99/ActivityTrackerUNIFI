//
// Created by redi on 12/02/21.
//

#include "Activity.h"

Activity::Activity(std::string newType, std::string newDescription, std::string startingMin, std::string startingHour, std::string finishingMin,
                   std::string finishingHour) : type(std::move(newType)), description(std::move(newDescription)){

    setStartFinishTime(std::move(startingMin), std::move(startingHour), std::move(finishingMin), std::move(finishingHour));

    time_t currentDate = time(nullptr);
    Date = localtime(&currentDate);

    timeSet -> day = Date -> tm_mday;
    timeSet -> month = Date -> tm_mon + 1;
    timeSet -> year = Date -> tm_year + 1900;

}

Activity::~Activity() {
    delete timeSet;
}

void Activity::subscribeView(Observer *newView) {
    activityViews.push_back(newView);
}

void Activity::unsubscribeView(Observer *removedView) {
    activityViews.remove(removedView);
}

void Activity::notifyChange() {
    for(auto view : activityViews)
        view -> updateView();
}

void Activity::setStartFinishTime(std::string startingMin, std::string startingHour, std::string finishingMin, std::string finishingHour) {
    timeSet = new startFinishTime;
    timeSet -> startingMin = std::move(startingMin);
    timeSet -> startingHour = std::move(startingHour);
    timeSet -> finishingMin = std::move(finishingMin);
    timeSet -> finishingHour = std::move(finishingHour);
}

startFinishTime *Activity::getTimeSet() const {
    return timeSet;
}

void Activity::setTimeSet(startFinishTime *newTimeSet) {
    Activity::timeSet = newTimeSet;
}

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &newDescription) {
    Activity::description = newDescription;
}

const std::string &Activity::getType() const {
    return type;
}

void Activity::setType(const std::string &newType) {
    Activity::type = newType;
}





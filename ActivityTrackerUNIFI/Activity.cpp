//
// Created by redi on 12/02/21.
//

#include "Activity.h"

Activity::Activity(std::string newType, std::string newDescription, int startingMin, int startingHour, int finishingMin,
                   int finishingHour) : type(std::move(newType)), description(std::move(newDescription)){

    setStartFinishTime(startingMin, startingHour, finishingMin, finishingHour);

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

void Activity::setStartFinishTime(int startingMin, int startingHour, int finishingMin, int finishingHour) {
    timeSet = new startFinishTime;
    timeSet -> startingMin = startingMin;
    timeSet -> startingHour = startingHour;
    timeSet -> finishingMin = finishingMin;
    timeSet -> finishingHour = finishingHour;
}

startFinishTime *Activity::getTimeSet() const {
    return timeSet;
}

void Activity::setTimeSet(startFinishTime *timeSet) {
    Activity::timeSet = timeSet;
}

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

const std::string &Activity::getType() const {
    return type;
}

void Activity::setType(const std::string &type) {
    Activity::type = type;
}





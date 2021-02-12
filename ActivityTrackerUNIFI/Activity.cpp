//
// Created by redi on 12/02/21.
//

#include "Activity.h"

Activity::Activity(const std::string newType, const std::string newDescription, int startingMin, int startingHour, int finishingMin,
                   int finishingHour) : type(newType), description(newDescription) {

    time_t currentTime = time(nullptr);
    startingTime = localtime(&currentTime);             // using local time for creating instance and then modify it
    finishingTime = localtime(&currentTime);            // for saving date and start/finish time of the activity

    startingTime -> tm_min = startingMin;
    startingTime -> tm_hour = startingHour;

    finishingTime -> tm_min = finishingMin;
    finishingTime -> tm_hour = finishingHour;

}

const std::string &Activity::getType() const {
    return type;
}

void Activity::setType(const std::string &newType) {
    Activity::type = newType;
}

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &newDescription) {
    Activity::description = newDescription;
}

Activity::~Activity() {
    delete startingTime;
    delete finishingTime;
}




//
// Created by redi on 12/02/21.
//

#include "Activity.h"

Activity::Activity(std::string type, std::string description, int startingMin, int startingHour, int finishingMin,
                   int finishingHour) : type(type), description(description) {

    time_t currentTime = time(nullptr);
    startingTime = localtime(&currentTime);             // using local time for creating instance and then modify it
    finishingTime = localtime(&currentTime);            // for saving date and start/finish time

    startingTime -> tm_min = startingMin;
    startingTime -> tm_hour = startingHour;

    finishingTime -> tm_min = finishingMin;
    finishingTime -> tm_hour = finishingHour;

}

const std::string &Activity::getType() const {
    return type;
}

void Activity::setType(const std::string &type) {
    Activity::type = type;
}

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

Activity::~Activity() {
    delete startingTime;
    delete finishingTime;
}




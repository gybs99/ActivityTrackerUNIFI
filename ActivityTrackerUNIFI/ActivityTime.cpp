//
// Created by redi on 12/03/21.
//

#include "ActivityTime.h"

ActivityTime::ActivityTime(std::string newStartingMin, std::string newStartingHour, std::string newFinishingMin, std::string newFinishingHour) :
                           Date() , startingMin(std::move(newStartingMin)), startingHour(std::move(newStartingHour)),
                           finishingMin(std::move(newFinishingMin)), finishingHour(std::move(newFinishingHour)) {



}

const std::string &ActivityTime::getStartingMin() const {
    return startingMin;
}

void ActivityTime::setStartingMin(const std::string &startingMin) {
    ActivityTime::startingMin = startingMin;
}

const std::string &ActivityTime::getStartingHour() const {
    return startingHour;
}

void ActivityTime::setStartingHour(const std::string &startingHour) {
    ActivityTime::startingHour = startingHour;
}

const std::string &ActivityTime::getFinishingMin() const {
    return finishingMin;
}

void ActivityTime::setFinishingMin(const std::string &finishingMin) {
    ActivityTime::finishingMin = finishingMin;
}

const std::string &ActivityTime::getFinishingHour() const {
    return finishingHour;
}

void ActivityTime::setFinishingHour(const std::string &finishingHour) {
    ActivityTime::finishingHour = finishingHour;
}

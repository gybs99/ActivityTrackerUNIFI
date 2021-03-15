//
// Created by redi on 12/03/21.
//

#include "ActivityTime.h"

ActivityTime::ActivityTime(std::string newStartingMin, std::string newStartingHour, std::string newFinishingMin, std::string newFinishingHour) :
                           Date(), startingMin(std::move(newStartingMin)), startingHour(std::move(newStartingHour)),
                           finishingMin(std::move(newFinishingMin)), finishingHour(std::move(newFinishingHour)) {

    if (checkTimeFormat() == 1)
        throw WrongTimeFormatException();

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

int ActivityTime::checkTimeFormat() {

    if (std::atoi(startingHour.c_str()) > std::atoi(finishingHour.c_str())) {
        return 1;
    }
    else {
        if (std::atoi(startingHour.c_str()) == std::atoi(finishingHour.c_str()))
            if (std::atoi(startingMin.c_str()) >= std::atoi(finishingMin.c_str()))
                return 1;
            else
            {
                return 0;
            }
        else {
            return 0;

        }
    }

}

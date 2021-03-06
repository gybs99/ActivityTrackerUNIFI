//
// Created by redi on 12/03/21.
//

#include "ActivityTime.h"

ActivityTime::ActivityTime(std::string newStartingMin, std::string newStartingHour, std::string newFinishingMin, std::string newFinishingHour) :
                           Date(), startingMin(std::move(newStartingMin)), startingHour(std::move(newStartingHour)),
                           finishingMin(std::move(newFinishingMin)), finishingHour(std::move(newFinishingHour)) {

    if (checkTimeFormat())
        throw WrongTimeFormatException();

}


const std::string &ActivityTime::getStartingMin() const {
    return startingMin;
}

const std::string &ActivityTime::getStartingHour() const {
    return startingHour;
}

const std::string &ActivityTime::getFinishingMin() const {
    return finishingMin;
}

const std::string &ActivityTime::getFinishingHour() const {
    return finishingHour;
}

bool ActivityTime::checkTimeFormat() {

    if (std::atoi(startingHour.c_str()) > std::atoi(finishingHour.c_str())) {
        return true;
    }
    else {
        if (std::atoi(startingHour.c_str()) == std::atoi(finishingHour.c_str()))
            if (std::atoi(startingMin.c_str()) >= std::atoi(finishingMin.c_str()))
                return true;
            else
            {
                return false;
            }
        else {
            return false;

        }
    }

}

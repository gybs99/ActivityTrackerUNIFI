//
// Created by redi on 01/03/21.
//

#include "ActivityTrackerHistory.h"


ActivityTrackerHistory::ActivityTrackerHistory() {

    systemTime = time(nullptr);
    currentDate = localtime((&systemTime));

}


void ActivityTrackerHistory::addRegister(std::shared_ptr<DailyActivityRegister>& newRegister) {

    history.push_back(newRegister);

}

void ActivityTrackerHistory::removeRegister(std::shared_ptr<DailyActivityRegister>& toDelete) {

    history.remove(toDelete);

}

const std::list<std::shared_ptr<DailyActivityRegister>> &ActivityTrackerHistory::getHistory() const {
    return history;
}

std::shared_ptr<DailyActivityRegister> ActivityTrackerHistory::searchTodayRegister() {


        auto historyIterator = history.begin();

        while (historyIterator != history.end()) {
            if (((*historyIterator)->getDate()->year == currentDate->tm_year + 1900) &&
                ((*historyIterator)->getDate()->month == currentDate->tm_mon + 1) &&
                ((*historyIterator)->getDate()->day == currentDate->tm_year))

                return (*historyIterator);

        }

        return nullptr;


}

std::shared_ptr<DailyActivityRegister> ActivityTrackerHistory::getSelectedRegister(std::string registerDate) {

    int positionOfSlash = registerDate.find('/');

    int day = std::atoi(registerDate.substr(0, positionOfSlash).c_str());

    int previousPosition = positionOfSlash;

    positionOfSlash = registerDate.find('/', positionOfSlash + 1);
    int month = std::atoi(registerDate.substr(previousPosition + 1, positionOfSlash - 1).c_str());

    int year = std::atoi(registerDate.substr(positionOfSlash + 1, registerDate.length() - 1).c_str());

    auto historyIterator = history.begin();

    while (historyIterator != history.end()) {
        if (((*historyIterator)->getDate()->year == year) &&
            ((*historyIterator)->getDate()->month == month) &&
            ((*historyIterator)->getDate()->day == day))

            return (*historyIterator);
        else
            historyIterator++;

    }

    return nullptr;


}

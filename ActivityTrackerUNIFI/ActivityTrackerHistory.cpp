//
// Created by redi on 01/03/21.
//

#include "ActivityTrackerHistory.h"


ActivityTrackerHistory::ActivityTrackerHistory() : systemTime(time(nullptr)) {

    currentDate = localtime((&systemTime));

}


void ActivityTrackerHistory::addRegister(std::shared_ptr<DailyActivityRegister>& newRegister) {

    history.push_back(newRegister);

}

void ActivityTrackerHistory::removeRegister(std::shared_ptr<DailyActivityRegister>& toDelete) {

    history.remove(toDelete);

}

std::shared_ptr<DailyActivityRegister> ActivityTrackerHistory::searchTodayRegister() {
    return searchRegister(currentDate -> tm_mday, currentDate -> tm_mon + 1, currentDate -> tm_year + 1900);
}

std::shared_ptr<DailyActivityRegister> ActivityTrackerHistory::getSelectedRegister(const std::string& registerDate) {

    int positionOfSlash = registerDate.find('/');

    int day = std::atoi(registerDate.substr(0, positionOfSlash).c_str());           // For the fact that in the view, register's dates are saved
                                                                                             // as strings, this method extract the needed information and convert it
    int previousPosition = positionOfSlash;                                                  // to integer

    positionOfSlash = registerDate.find('/', positionOfSlash + 1);
    int month = std::atoi(registerDate.substr(previousPosition + 1, positionOfSlash - 1).c_str());

    int year = std::atoi(registerDate.substr(positionOfSlash + 1, registerDate.length() - 1).c_str());

    return searchRegister(day, month, year);


}

std::shared_ptr<DailyActivityRegister> ActivityTrackerHistory::searchRegister(int day, int month, int year) {

    auto historyIterator = history.begin();

    while (historyIterator != history.end()) {
        if (((*historyIterator)->getRegisterDate().getYear() == year) &&
            ((*historyIterator)->getRegisterDate().getMonth() == month) &&
            ((*historyIterator)->getRegisterDate().getDay() == day))

            return (*historyIterator);
        else
            historyIterator++;

    }

    return nullptr;

}

bool ActivityTrackerHistory::isHistoryEmpty() {
    return history.empty();
}

int ActivityTrackerHistory::getHistoryDimension() {
    return history.size();
}

std::shared_ptr<DailyActivityRegister> ActivityTrackerHistory::searchRegister(int registerPos) {

    auto itr = history.begin();

    for (int i = 0; i < registerPos; ++i) {
        itr++;
    }

    return (*itr);

}

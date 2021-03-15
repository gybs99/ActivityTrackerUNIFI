//
// Created by redi on 12/03/21.
//

#ifndef ACTIVITYTRACKERUNIFI_WRONGTIMEFORMATEXCEPTION_H
#define ACTIVITYTRACKERUNIFI_WRONGTIMEFORMATEXCEPTION_H
#include <exception>

class WrongTimeFormatException : public std::exception {

public:
    WrongTimeFormatException();
};


#endif //ACTIVITYTRACKERUNIFI_WRONGTIMEFORMATEXCEPTION_H

//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_SUBJECT_H
#define ACTIVITYTRACKERUNIFI_SUBJECT_H

#include "Observer.h"
#include <memory>

class Subject {
public:

    virtual void subscribeView(Observer* newView) = 0;
    virtual void unsubscribeView(Observer* removedView) = 0;
    virtual void notifyChange() = 0;

    virtual ~Subject() {}

};


#endif //ACTIVITYTRACKERUNIFI_SUBJECT_H

//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_OBSERVER_H
#define ACTIVITYTRACKERUNIFI_OBSERVER_H


class Observer {
public:

    virtual ~Observer() {}

    virtual void updateView() = 0;
    virtual void attachView() = 0;
    virtual void detachView() = 0;

};


#endif //ACTIVITYTRACKERUNIFI_OBSERVER_H

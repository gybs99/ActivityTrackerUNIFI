//
// Created by redi on 19/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H

#include "Activity.h"
#include "DailyActivityRegister.h"
#include "ActivityTrackerHistory.h"


class ActivityTrackerController {

public:

    explicit ActivityTrackerController(std::shared_ptr<ActivityTrackerHistory> loadingHistory);

    int createActivity(std::string newType, std::string newDescription, const ActivityTime& newTime);

    bool removeActivity(const std::shared_ptr<Activity>& selectedActivity);

    void modifyActivity(std::shared_ptr<Activity>& selectedActivity, std::string newType, std::string newDescription, const ActivityTime& newTime);

    std::shared_ptr<Activity> getActivitySelected(int activitySelected);

    std::shared_ptr<DailyActivityRegister> getRegisterSelected(const std::string& date);         // Used to take the right register depending the entry clicked
                                                                                          // in history's view

    std::shared_ptr<DailyActivityRegister> getRegisterSelected(int registerPos);         // Used in the history's view for putting all registers inside
                                                                                          // the list box
    void removeRegister();

    const std::shared_ptr<DailyActivityRegister> &getTodayRegister() const;

    const std::shared_ptr<Activity> &getManagedActivity() const;

    std::shared_ptr<DailyActivityRegister> searchRegister(int day, int month, int year);

    bool isHistoryEmpty();

    int getHistoryDimension();


private:

    std::shared_ptr<Activity> managedActivity {nullptr};
    std::shared_ptr<DailyActivityRegister> todayRegister {nullptr};
    std::shared_ptr<ActivityTrackerHistory> loadedHistory {nullptr};

};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H

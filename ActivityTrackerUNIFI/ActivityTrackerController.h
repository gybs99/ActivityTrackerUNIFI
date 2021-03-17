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

    int createActivity(std::string newType, std::string newDescription, ActivityTime newTime);

    bool removeActivity(const std::shared_ptr<Activity>& selectedActivity);

    void modifyActivity(std::shared_ptr<Activity>& selectedActivity, std::string newType, std::string newDescription, const ActivityTime& newTime);

    const std::shared_ptr<Activity> &getActivitySelected(int activitySelected);

    std::shared_ptr<DailyActivityRegister> getRegisterSelected(std::string date);

    std::shared_ptr<DailyActivityRegister>& getRegisterSelected(int registerPos);

    void removeRegister();

    const std::shared_ptr<DailyActivityRegister> &getTodayRegister() const;

    const std::shared_ptr<ActivityTrackerHistory> &getLoadedHistory() const;

    const std::shared_ptr<Activity> &getManagedActivity() const;

    bool isHistoryEmpty();

    int getHistoryDimension();


private:

    std::shared_ptr<Activity> managedActivity {nullptr};
    std::shared_ptr<DailyActivityRegister> todayRegister {nullptr};
    std::shared_ptr<ActivityTrackerHistory> loadedHistory {nullptr};

};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERCONTROLLER_H

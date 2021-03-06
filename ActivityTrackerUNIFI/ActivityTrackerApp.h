//
// Created by redi on 10/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERAPP_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERAPP_H

#include <iostream>
#include <memory>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainMenu.h"
#include "Activity.h"
#include "ActivityView.h"
#include "AddNewActivityView.h"
#include "ActivityTrackerController.h"


enum
{
    ID_Main = 1
};


class ActivityTrackerApp : public wxApp {
public:

    ActivityTrackerApp() = default;
    bool OnInit() override;
    bool OnExceptionInMainLoop() override;

private:

    std::shared_ptr<ActivityTrackerHistory> history;
    MainMenu* mainMenuWindow {nullptr};
    std::shared_ptr<ActivityTrackerController> appController;

};

#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERAPP_H

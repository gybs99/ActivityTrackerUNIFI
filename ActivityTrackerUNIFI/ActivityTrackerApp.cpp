//
// Created by redi on 10/02/21.
//

#include "ActivityTrackerApp.h"


wxIMPLEMENT_APP(ActivityTrackerApp);

bool ActivityTrackerApp::OnInit() {
    mainMenuWindow = new MainMenu();
    mainMenuWindow ->SetId(ID_Main);

    newActivity = std::make_shared<Activity>("Sport", "Today i've run for 30 minutes.", 10, 10, 30, 12);
    actView = new ActivityView(newActivity);
    addActivityView = new AddNewActivityView();

    mainMenuWindow -> Show();
    actView -> Show();
    addActivityView -> Show();
    return true;
}


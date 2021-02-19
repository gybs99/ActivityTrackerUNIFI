//
// Created by redi on 10/02/21.
//

#include "ActivityTrackerApp.h"


wxIMPLEMENT_APP(ActivityTrackerApp);

bool ActivityTrackerApp::OnInit() {
    appController = std::make_shared<ActivityTrackerController>();
    mainMenuWindow = new MainMenu(appController);
    mainMenuWindow ->SetId(ID_Main);


    addActivityView = new AddNewActivityView(mainMenuWindow, appController);

    mainMenuWindow -> Show();
    return true;
}


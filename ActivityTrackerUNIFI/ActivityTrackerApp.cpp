//
// Created by redi on 10/02/21.
//

#include "ActivityTrackerApp.h"


wxIMPLEMENT_APP(ActivityTrackerApp);

bool ActivityTrackerApp::OnInit() {
    appController = std::make_shared<ActivityTrackerController>();
    mainMenuWindow = new MainMenu(appController);
    mainMenuWindow ->SetId(ID_Main);
    mainMenuWindow -> Show();

    DailyActivityRegisterView* registerView = new DailyActivityRegisterView();
    registerView -> Show();

    return true;
}

bool ActivityTrackerApp::OnExceptionInMainLoop() {

    wxMessageBox("An error has occurred, please restart the app");
    return false;

}


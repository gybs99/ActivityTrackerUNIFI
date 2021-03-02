//
// Created by redi on 10/02/21.
//

#include "ActivityTrackerApp.h"


wxIMPLEMENT_APP(ActivityTrackerApp);

bool ActivityTrackerApp::OnInit() {

    history = std::make_shared<ActivityTrackerHistory>();
    appController = std::make_shared<ActivityTrackerController>(history);

    mainMenuWindow = new MainMenu(appController);
    mainMenuWindow ->SetId(ID_Main);
    mainMenuWindow -> Show();

    return true;
}

bool ActivityTrackerApp::OnExceptionInMainLoop() {

    wxMessageBox(wxT("An error has occurred, please restart the app"));
    return false;

}


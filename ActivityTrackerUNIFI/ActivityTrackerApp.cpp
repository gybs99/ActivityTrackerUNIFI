//
// Created by redi on 10/02/21.
//

#include "ActivityTrackerApp.h"


wxIMPLEMENT_APP(ActivityTrackerApp);

bool ActivityTrackerApp::OnInit() {
    mainMenuWindow = new MainMenu();
    mainMenuWindow ->SetId(ID_Main);

    newActivity = std::make_shared<Activity>("Sport", "Oggi ho fatto 30 minuti di corsa.", 10, 10, 10, 10);
    actView = new ActivityView(newActivity);

    mainMenuWindow -> Show();
    actView -> Show();
    return true;
}


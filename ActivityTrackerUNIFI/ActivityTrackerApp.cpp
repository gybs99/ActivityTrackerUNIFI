//
// Created by redi on 10/02/21.
//

#include "ActivityTrackerApp.h"

wxIMPLEMENT_APP(ActivityTrackerApp);



bool ActivityTrackerApp::OnInit() {
    mainMenuWindow = new MainMenu();
    mainMenuWindow -> Show();
    return true;
}

ActivityTrackerApp::ActivityTrackerApp() {

}

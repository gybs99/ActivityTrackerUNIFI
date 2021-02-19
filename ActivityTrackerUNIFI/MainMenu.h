//
// Created by redi on 10/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_MAINMENU_H
#define ACTIVITYTRACKERUNIFI_MAINMENU_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "AddNewActivityView.h"
#include "ActivityTrackerController.h"
#endif

enum
{
    ID_LookRegister = 1,
    ID_SearchDay = 2,
    ID_Today = 3,
    ID_AddActivity = 4,
    ID_About = 5,
    ID_SignInButton = 6
};

class MainMenu : public wxFrame{
public:

    MainMenu(std::shared_ptr<ActivityTrackerController>);
    void assembleMenuBar();
    void setStaticText();
    void setBoxSizer();
    void onInfo(wxCommandEvent& event);
    void onSignInButton(wxCommandEvent& event);
    void onAddActivityMenu(wxCommandEvent& event);

private:

    wxBoxSizer* mainMenuSizer {nullptr};

    wxStaticText* introText {nullptr};
    wxStaticText* dayText {nullptr};
    wxStaticText* lookTodayText {nullptr};

    wxMenuBar* mainMenuBar {nullptr};
    wxMenu* registerField {nullptr};
    wxMenu* todayField {nullptr};
    wxMenu* aboutField {nullptr};

    wxButton* lookTodayButton {nullptr};

    wxFrame* addActivityView {nullptr};

    std::shared_ptr<ActivityTrackerController> controller;

    wxDECLARE_EVENT_TABLE();

};


#endif //ACTIVITYTRACKERUNIFI_MAINMENU_H

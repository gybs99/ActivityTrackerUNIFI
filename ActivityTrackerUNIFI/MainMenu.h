//
// Created by redi on 10/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_MAINMENU_H
#define ACTIVITYTRACKERUNIFI_MAINMENU_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>

#include "AddNewActivityView.h"
#include "ActivityTrackerController.h"
#include "DailyActivityRegisterView.h"

enum
{
    ID_LookHistory = 1,
    ID_Today = 2,
    ID_AddActivity = 3,
    ID_About = 4,
    ID_SignInButton = 5
};

class MainMenu : public wxFrame{
public:

    explicit MainMenu(std::shared_ptr<ActivityTrackerController> newController);

    void assembleMenuBar();

    void setStaticText();

    void setBoxSizer();

    void onInfo(wxCommandEvent& event);

    void onSignInButton(wxCommandEvent& event);

    void onAddActivityMenu(wxCommandEvent& event);

    void onToday(wxCommandEvent& event);

    void onShowHistory(wxCommandEvent& event);


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
    wxFrame* dailyRegisterView {nullptr};

    std::shared_ptr<ActivityTrackerController> controller;

    wxDECLARE_EVENT_TABLE();

};


#endif //ACTIVITYTRACKERUNIFI_MAINMENU_H

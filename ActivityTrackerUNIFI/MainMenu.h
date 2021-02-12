//
// Created by redi on 10/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_MAINMENU_H
#define ACTIVITYTRACKERUNIFI_MAINMENU_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

enum
{
    ID_LookRegister = 1,
    ID_SearchDay = 2,
    ID_Today = 3,
    ID_AddActivity = 4,
    ID_About = 5
};

class MainMenu : public wxFrame{
public:

    MainMenu();
    void assembleMenuBar();
    void setStaticText();
    void setBoxSizer();
    void OnInfo(wxCommandEvent& event);

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
    wxDECLARE_EVENT_TABLE();

};


#endif //ACTIVITYTRACKERUNIFI_MAINMENU_H

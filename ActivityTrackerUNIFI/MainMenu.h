//
// Created by redi on 10/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_MAINMENU_H
#define ACTIVITYTRACKERUNIFI_MAINMENU_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainMenu : public wxFrame{
public:
    MainMenu();
    void assembleMenuBar();
    void setStaticText();
    void setBoxSizer();

private:
    wxBoxSizer* mainMenuSizer{};
    wxStaticText* introText{};
    wxStaticText* dayText{};
    wxStaticText* lookTodayText{};
    wxMenuBar* mainMenuBar{};
    wxMenu* registerField{};
    wxMenu* todayField{};
    wxMenu* aboutField{};
    wxButton* lookTodayButton;
};


#endif //ACTIVITYTRACKERUNIFI_MAINMENU_H

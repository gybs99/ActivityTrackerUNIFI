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

private:
    wxBoxSizer* mainMenuSizer;
    wxStaticText* introText;
};


#endif //ACTIVITYTRACKERUNIFI_MAINMENU_H

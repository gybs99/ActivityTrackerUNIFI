//
// Created by redi on 15/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ADDNEWACTIVITYVIEW_H
#define ACTIVITYTRACKERUNIFI_ADDNEWACTIVITYVIEW_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <vector>

class AddNewActivityView : public wxFrame {

public:
    AddNewActivityView();
private:
    wxStaticText* typeText;
    wxBoxSizer* typeSizer;
    wxChoice* typeChoiceList;
};


#endif //ACTIVITYTRACKERUNIFI_ADDNEWACTIVITYVIEW_H

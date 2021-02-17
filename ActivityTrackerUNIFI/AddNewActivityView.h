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
    AddNewActivityView(wxFrame* mainMenu);

    void createMinHoursVectors();

    void assembleTypeView();

    void assembleDescriptionView();

    void assembleDurationView();

    void assembleTimeStartView();

    void assembleTimeFinishView();

    void assembleButtonsView();

    void onClose(wxCloseEvent& event);

private:

    const int static numberOfTypes = 4;
    const int static numberOfMinutes = 60;
    const int static numberOfHours = 24;

    wxStaticText* typeText;
    wxStaticText* descriptionText;
    wxStaticText* durationText;
    wxStaticText* timeFinishText;
    wxStaticText* timeSpacer1;
    wxStaticText* timeSpacer2;

    wxTextCtrl* descriptionTextBox;

    wxBoxSizer* viewSizer;
    wxBoxSizer* typeSizer;
    wxBoxSizer* durationSizer;
    wxBoxSizer* timeFinishSizer;
    wxBoxSizer* buttonsSizer;

    wxButton* acceptButton;
    wxButton* cancelButton;

    wxComboBox* typeChoiceList;
    wxComboBox* startingHourList;
    wxComboBox* startingMinList;
    wxComboBox* finishingHourList;
    wxComboBox* finishingMinList;

    wxString types[numberOfTypes] = {wxT("Sport"), wxT("Work"), wxT("Hobby"), wxT("Other")};
    wxString hours[numberOfHours];
    wxString mins[numberOfMinutes];

    wxDECLARE_EVENT_TABLE();

};


#endif //ACTIVITYTRACKERUNIFI_ADDNEWACTIVITYVIEW_H

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
#include <ctime>
#include "ActivityTrackerController.h"

enum
{
    ID_CancelButton = 1,
    ID_CreateButton = 2
};

class AddNewActivityView : public wxFrame {

public:
    AddNewActivityView(wxFrame* mainMenu, std::shared_ptr<ActivityTrackerController>);

    void createMinHoursVectors();

    void assembleTypeView();

    void assembleDescriptionView();

    void assembleDurationView();

    void assembleTimeStartView();

    void assembleTimeFinishView();

    void assembleButtonsView();

    void onClose(wxCloseEvent& event);

    void onCancel(wxCommandEvent& event);

    void onCreate(wxCommandEvent& event);

    void resetForm();

private:

    const int static numberOfTypes {5};
    const int static numberOfMinutes {60};
    const int static numberOfHours {24};

    wxStaticText* typeText {nullptr};
    wxStaticText* descriptionText {nullptr};
    wxStaticText* durationText {nullptr};
    wxStaticText* timeFinishText {nullptr};
    wxStaticText* timeSpacer1 {nullptr};
    wxStaticText* timeSpacer2 {nullptr};

    wxTextCtrl* descriptionTextBox {nullptr};

    wxBoxSizer* viewSizer {nullptr};
    wxBoxSizer* typeSizer {nullptr};
    wxBoxSizer* durationSizer {nullptr};
    wxBoxSizer* timeFinishSizer {nullptr};
    wxBoxSizer* buttonsSizer {nullptr};

    wxButton* acceptButton {nullptr};
    wxButton* cancelButton {nullptr};

    wxComboBox* typeChoiceList {nullptr};
    wxComboBox* startingHourList {nullptr};
    wxComboBox* startingMinList {nullptr};
    wxComboBox* finishingHourList {nullptr};
    wxComboBox* finishingMinList {nullptr};

    wxString types[numberOfTypes] = {wxT("..."),wxT("Sport"), wxT("Work"), wxT("Hobby"), wxT("Other")};
    wxString hours[numberOfHours];
    wxString mins[numberOfMinutes];

    std::shared_ptr<ActivityTrackerController> controller;

    wxDECLARE_EVENT_TABLE();

};


#endif //ACTIVITYTRACKERUNIFI_ADDNEWACTIVITYVIEW_H

//
// Created by redi on 15/02/21.
//

#include "AddNewActivityView.h"

wxBEGIN_EVENT_TABLE(AddNewActivityView, wxFrame)
    EVT_BUTTON(ID_CancelButton, AddNewActivityView::onCancel)
    EVT_CLOSE(AddNewActivityView::onClose)
wxEND_EVENT_TABLE()

AddNewActivityView::AddNewActivityView(wxFrame* mainMenu) : wxFrame(mainMenu, wxID_ANY, "Add a new Activity") {

    this -> SetMinSize(wxSize(600,500));

    viewSizer = new wxBoxSizer(wxVERTICAL);

    assembleTypeView();

    assembleDescriptionView();

    assembleDurationView();

    assembleButtonsView();

    viewSizer -> Add(typeSizer, 0, wxEXPAND | wxALL, 0);
    viewSizer -> Add(descriptionText, 0, wxTOP | wxRIGHT | wxLEFT, 20);
    viewSizer -> Add(descriptionTextBox, 1, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 20);
    viewSizer -> Add(durationSizer, 0, wxEXPAND | wxALL, 0);
    viewSizer -> Add(timeFinishSizer, 0, wxEXPAND | wxALL, 0);
    viewSizer -> Add(buttonsSizer, 0, wxEXPAND | wxALL, 0);

    time_t currentTime = time(nullptr);
    struct tm* displayDate = localtime((&currentTime));

    this -> CreateStatusBar();
    this -> SetStatusText(std::to_string(displayDate -> tm_mday) + "/" + std::to_string(displayDate -> tm_mon + 1) +
                    "/" + std::to_string(displayDate -> tm_year + 1900));
    this -> SetSizer(viewSizer);
}

void AddNewActivityView::createMinHoursVectors() {
    for (int i = 0; i < 24; ++i) {
       if(i < 10)
           hours[i] = std::to_string(0) + std::to_string(i);
       else
           hours[i] = std::to_string(i);
    }

    for (int i = 0; i < 60; ++i) {
        if(i < 10)
            mins[i] = std::to_string(0) + std::to_string(i);
        else
            mins[i] = std::to_string(i);
    }
}

void AddNewActivityView::assembleDescriptionView() {

    descriptionText = new wxStaticText(this, wxID_ANY, "Description: ");
    descriptionText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    descriptionTextBox = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition,
                                        wxDefaultSize, wxTE_MULTILINE);
    descriptionTextBox -> SetFont(wxFont(12,wxROMAN, wxNORMAL, wxNORMAL));

    durationText = new wxStaticText(this, wxID_ANY, "Duration:    Start ");
    durationText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

}

void AddNewActivityView::assembleDurationView() {

    createMinHoursVectors();

    assembleTimeStartView();

    assembleTimeFinishView();

}

void AddNewActivityView::assembleTypeView() {

    typeText = new wxStaticText(this, wxID_ANY, "Type: ");
    typeText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    typeChoiceList = new wxComboBox(this, wxID_ANY, "...", wxDefaultPosition, wxSize(100,40),
                                    5, types, wxCB_READONLY);

    typeSizer = new wxBoxSizer(wxHORIZONTAL);
    typeSizer -> Add(typeText, 0 , wxALL, 20);
    typeSizer -> Add(typeChoiceList, 0, wxALL, 20);

}

void AddNewActivityView::assembleTimeStartView() {

    startingHourList = new wxComboBox(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80, 40),
                                      numberOfHours, hours, wxCB_READONLY);

    timeSpacer1 = new wxStaticText(this, wxID_ANY, ":");
    timeSpacer1 -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    startingMinList = new wxComboBox(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,40),
                                     numberOfMinutes, mins, wxCB_READONLY);


    durationSizer = new wxBoxSizer(wxHORIZONTAL);
    durationSizer -> Add(durationText, 0, wxALL, 20);
    durationSizer -> Add(startingHourList, 0, wxALL, 20);
    durationSizer -> Add(timeSpacer1, 0, wxALL, 20);
    durationSizer -> Add(startingMinList, 0, wxALL, 20);

}

void AddNewActivityView::assembleTimeFinishView() {

    finishingHourList = new wxComboBox(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80, 40),
                                       numberOfHours, hours, wxCB_READONLY);

    timeSpacer2 = new wxStaticText(this, wxID_ANY, ":");
    timeSpacer2 -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    finishingMinList = new wxComboBox(this, wxID_ANY, "00", wxDefaultPosition, wxSize(80,40),
                                      numberOfMinutes, mins, wxCB_READONLY);

    timeFinishText = new wxStaticText(this, wxID_ANY, "                  Finish ");
    timeFinishText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    timeFinishSizer = new wxBoxSizer(wxHORIZONTAL);
    timeFinishSizer -> Add(timeFinishText, 0, wxALL, 20);
    timeFinishSizer -> Add(finishingHourList, 0, wxALL, 20);
    timeFinishSizer -> Add(timeSpacer2, 0, wxALL, 20);
    timeFinishSizer -> Add(finishingMinList, 0, wxALL, 20);

}

void AddNewActivityView::assembleButtonsView() {

    buttonsSizer = new wxBoxSizer(wxHORIZONTAL);
    acceptButton = new wxButton(this, wxID_ANY, "Create");
    cancelButton = new wxButton(this, ID_CancelButton, "Cancel");

    buttonsSizer -> AddStretchSpacer(2);
    buttonsSizer -> Add(acceptButton, 0, wxALIGN_RIGHT | wxALL, 20);
    buttonsSizer -> Add(cancelButton, 0, wxALIGN_RIGHT | wxALL, 20);

}

void AddNewActivityView::onClose(wxCloseEvent& event) {

    resetForm();
    this -> Show(false);
    m_parent -> Enable(true);

}

void AddNewActivityView::onCancel(wxCommandEvent& event) {

    resetForm();
    this -> Show(false);
    m_parent -> Enable(true);

}

void AddNewActivityView::resetForm() {

    typeChoiceList -> SetValue("...");
    descriptionTextBox -> SetValue("");
    startingHourList -> SetValue("00");
    startingMinList -> SetValue("00");
    finishingMinList -> SetValue("00");
    finishingHourList -> SetValue("00");

}

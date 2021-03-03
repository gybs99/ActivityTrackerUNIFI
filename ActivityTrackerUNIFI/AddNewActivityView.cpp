//
// Created by redi on 15/02/21.
//

#include "AddNewActivityView.h"

wxBEGIN_EVENT_TABLE(AddNewActivityView, wxFrame)
    EVT_BUTTON(ID_CreateButton, AddNewActivityView::onCreate)
    EVT_BUTTON(ID_CancelButton, AddNewActivityView::onCancel)
    EVT_CLOSE(AddNewActivityView::onClose)
wxEND_EVENT_TABLE()

AddNewActivityView::AddNewActivityView(wxFrame* mainMenu, std::shared_ptr<ActivityTrackerController> controller) :
                                                wxFrame(mainMenu, wxID_ANY, "Add a new Activity"), controller(std::move(controller)) {


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

AddNewActivityView::AddNewActivityView(wxFrame* registerView, std::shared_ptr<ActivityTrackerController> newController, std::shared_ptr<Activity> selectedActivity)
                                        : AddNewActivityView(registerView, std::move(newController)){

    activityToModify = std::move(selectedActivity);

    typeChoiceList -> SetValue(activityToModify -> getType());
    descriptionTextBox -> SetValue(activityToModify -> getDescription());

    startingHourList -> SetValue(activityToModify -> getTimeSet() -> startingHour);                 // This constructor assemble the view in Modify mode,
    startingMinList -> SetValue(activityToModify -> getTimeSet() -> startingMin);                   // so when i press "Modify" in activity view, this will appear

    finishingHourList -> SetValue(activityToModify -> getTimeSet() -> finishingHour);
    finishingMinList -> SetValue(activityToModify -> getTimeSet() -> finishingMin);

    acceptButton -> SetLabel("Modify");

    this -> SetLabel("Modify an activity");

    this -> SetStatusText(std::to_string(activityToModify -> getTimeSet() -> day) + "/" + std::to_string(activityToModify -> getTimeSet() -> month)
                            + "/" + std::to_string(activityToModify -> getTimeSet() -> year));

    acceptButton -> Bind(wxEVT_BUTTON, &AddNewActivityView::onModify, this, ID_CreateButton);

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

    acceptButton = new wxButton(this, ID_CreateButton, "Create");
    cancelButton = new wxButton(this, ID_CancelButton, "Cancel");

    buttonsSizer -> AddStretchSpacer(2);
    buttonsSizer -> Add(acceptButton, 0, wxALIGN_RIGHT | wxALL, 20);
    buttonsSizer -> Add(cancelButton, 0, wxALIGN_RIGHT | wxALL, 20);

}

void AddNewActivityView::onClose(wxCloseEvent& event) {

    m_parent -> Enable(true);
    this -> Destroy();

}

void AddNewActivityView::onCancel(wxCommandEvent& event) {

    m_parent -> Enable(true);
    this -> Destroy();

}


void AddNewActivityView::onCreate(wxCommandEvent &event) {

    int checkResult = checkForm();

    if(checkResult == 1) {
        wxMessageBox(wxT("To save your done task, you need to set almost a type."), wxT("Warning!"), wxOK | wxICON_EXCLAMATION);
        return;
    } else if (checkResult == 2) {
        wxMessageBox(wxT("Time format is not valid! Please fix it and try again."), wxT("Warning!"), wxOK | wxICON_EXCLAMATION);
        return;
    }

    controller -> createActivity(typeChoiceList -> GetValue().ToStdString(),descriptionTextBox -> GetValue().ToStdString(),
                                 startingMinList -> GetValue().ToStdString(), startingHourList -> GetValue().ToStdString(),
                                 finishingMinList -> GetValue().ToStdString(), finishingHourList -> GetValue().ToStdString());
    wxMessageBox(wxT("Your done task is added to your register! \n Check the daily register for review it"), wxT("Activity added"), wxOK | wxICON_INFORMATION);
    m_parent -> Enable(true);
    this -> Destroy();

}

void AddNewActivityView::onModify(wxCommandEvent &event) {

    int checkResult = checkForm();

    if(checkResult == 1) {
        wxMessageBox(wxT("To save your done task, you need to set almost a type."), wxT("Warning!"), wxOK | wxICON_EXCLAMATION);
        return;
    } else if (checkResult == 2) {
        wxMessageBox(wxT("Time format is not valid! Please fix it and try again."), wxT("Warning!"), wxOK | wxICON_EXCLAMATION);
        return;
    }

    controller -> modifyActivity(activityToModify, typeChoiceList -> GetValue().ToStdString(), descriptionTextBox -> GetValue().ToStdString(),
                                 startingMinList -> GetValue().ToStdString(), startingHourList -> GetValue().ToStdString(), finishingMinList ->
                                 GetValue().ToStdString(), finishingHourList -> GetValue().ToStdString());
    wxMessageBox(wxT("Activity successfully modified!"), wxT("Done!"), wxOK | wxICON_INFORMATION);
    m_parent -> Enable(true);
    this -> Destroy();

}

int AddNewActivityView::checkForm() {

    if (typeChoiceList -> GetValue() == "...")
        return 1;
    else {
        if (std::atoi(startingHourList -> GetValue()) > std::atoi(finishingHourList -> GetValue())) {
            return 2;
        }
        else {
            if (std::atoi(startingHourList -> GetValue()) == std::atoi(finishingHourList -> GetValue()))
                if (std::atoi(startingMinList -> GetValue()) >= std::atoi(finishingMinList -> GetValue()))
                    return 2;
                else
                {
                    return 0;
                }
            else {
                return 0;

            }
        }
    }

}

wxComboBox *AddNewActivityView::getTypeChoiceList() const {
    return typeChoiceList;
}

wxTextCtrl *AddNewActivityView::getDescriptionTextBox() const {
    return descriptionTextBox;
}

wxComboBox *AddNewActivityView::getStartingHourList() const {
    return startingHourList;
}

wxComboBox *AddNewActivityView::getStartingMinList() const {
    return startingMinList;
}

wxComboBox *AddNewActivityView::getFinishingHourList() const {
    return finishingHourList;
}

wxComboBox *AddNewActivityView::getFinishingMinList() const {
    return finishingMinList;
}

const std::shared_ptr<ActivityTrackerController> &AddNewActivityView::getController() const {
    return controller;
}


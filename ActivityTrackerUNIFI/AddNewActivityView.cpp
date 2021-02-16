//
// Created by redi on 15/02/21.
//

#include "AddNewActivityView.h"

AddNewActivityView::AddNewActivityView() : wxFrame(nullptr, wxID_ANY, "Add a new Activity") {

    SetMinSize(wxSize(600,500));

    typeText = new wxStaticText(this, wxID_ANY, "Type: ");
    typeText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    typeChoiceList = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 4, types);

    typeSizer = new wxBoxSizer(wxHORIZONTAL);
    typeSizer -> Add(typeText, 0 , wxALL, 20);
    typeSizer -> Add(typeChoiceList, 0, wxALL, 20);

    viewSizer = new wxBoxSizer(wxVERTICAL);


    descriptionText = new wxStaticText(this, wxID_ANY, "Description: ");
    descriptionText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    descriptionTextBox = new wxTextCtrl(this, wxID_ANY, "");

    durationText = new wxStaticText(this, wxID_ANY, "Duration:    Start ");
    durationText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    createMinHoursVectors();
    startingHourList = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 40),
                                      numberOfHours, hours, wxCB_READONLY);

    timeSpacer1 = new wxStaticText(this, wxID_ANY, ":");
    timeSpacer1 -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    startingMinList = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxSize(80,40),
                                     numberOfMinutes, mins, wxCB_READONLY);


    durationSizer = new wxBoxSizer(wxHORIZONTAL);
    durationSizer -> Add(durationText, 0, wxALL, 20);
    durationSizer -> Add(startingHourList, 0, wxALL, 20);
    durationSizer -> Add(timeSpacer1, 0, wxALL, 20);
    durationSizer -> Add(startingMinList, 0, wxALL, 20);

    finishingHourList = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxSize(80, 40),
                  numberOfHours, hours, wxCB_READONLY);

    timeSpacer2 = new wxStaticText(this, wxID_ANY, ":");
    timeSpacer2 -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    finishingMinList = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxSize(80,40),
                                    numberOfMinutes, mins, wxCB_READONLY);

    timeFinishText = new wxStaticText(this, wxID_ANY, "                  Finish ");
    timeFinishText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    timeFinishSizer = new wxBoxSizer(wxHORIZONTAL);
    timeFinishSizer -> Add(timeFinishText, 0, wxALL, 20);
    timeFinishSizer -> Add(finishingHourList, 0, wxALL, 20);
    timeFinishSizer -> Add(timeSpacer2, 0, wxALL, 20);
    timeFinishSizer -> Add(finishingMinList, 0, wxALL, 20);

    viewSizer -> Add(typeSizer, 0, wxEXPAND | wxALL, 0);
    viewSizer -> Add(descriptionText, 0, wxTOP | wxRIGHT | wxLEFT, 20);
    viewSizer -> Add(descriptionTextBox, 1, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 20);
    viewSizer -> Add(durationSizer, 0, wxEXPAND | wxALL, 0);
    viewSizer -> Add(timeFinishSizer, 0, wxEXPAND | wxALL, 0);

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

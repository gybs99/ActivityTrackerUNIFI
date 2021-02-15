//
// Created by redi on 15/02/21.
//

#include "AddNewActivityView.h"

AddNewActivityView::AddNewActivityView() : wxFrame(nullptr, wxID_ANY, "Add a new Activity") {

    typeText = new wxStaticText(this, wxID_ANY, "Type");
    typeText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    types -> push_back("Sport");
    typeChoiceList = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2);

}

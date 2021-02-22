//
// Created by redi on 22/02/21.
//

#include "DailyActivityRegisterView.h"

DailyActivityRegisterView::DailyActivityRegisterView() : wxFrame(nullptr, wxID_ANY, "Register") {

    viewSizer = new wxBoxSizer(wxVERTICAL);
    listSizer = new wxBoxSizer(wxHORIZONTAL);

    listOfActivity = new wxListBox(this, wxID_ANY, wxDefaultPosition);
    listOfActivity -> Append("Example 1");
    listOfActivity -> Append("Example 2");

    listSizer -> Add(listOfActivity,1, wxEXPAND);

    addButton = new wxButton(this, wxID_ANY, "Add Activity");

    viewSizer -> Add(listSizer, 1, wxEXPAND | wxALL, 20);
    viewSizer -> Add(addButton, 0, wxCENTER | wxALL, 20);

    this -> SetSizer(viewSizer);

}

void DailyActivityRegisterView::updateView() {

}

void DailyActivityRegisterView::attachView() {

}

void DailyActivityRegisterView::detachView() {

}

DailyActivityRegisterView::~DailyActivityRegisterView() {

}

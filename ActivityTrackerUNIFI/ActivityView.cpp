//
// Created by redi on 12/02/21.
//

#include "ActivityView.h"


ActivityView::ActivityView(std::shared_ptr<Activity> newActivity): wxFrame(nullptr, wxID_ANY, "Activity Visual",
                      wxDefaultPosition, wxSize(600,400)), activityViewed(std::move(newActivity)) {

    attachView();

    assembleMenuBar();

    this -> CreateStatusBar();

    createViewText();

    this -> SetStatusText("Activity registered the " + std::to_string(activityViewed -> getTimeSet() -> day) + "/" +
                    std::to_string(activityViewed -> getTimeSet() -> month) + "/" + std::to_string(activityViewed ->
                    getTimeSet() -> year));

    backButton = new wxButton(this, 8, "OK");

    topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer -> Add(activityType, 1, wxEXPAND | wxALL, 20);
    topSizer -> Add(activityDescription, 1, wxEXPAND | wxALL, 20);

    bottomSizer = new wxBoxSizer(wxVERTICAL);
    bottomSizer -> Add(activityDuration, 0, wxEXPAND | wxALL, 20);
    bottomSizer -> Add(backButton, 0, wxALIGN_RIGHT, 20);

    topSizer -> Add(bottomSizer, 0, wxEXPAND | wxALL, 20);

    this -> SetMinSize(wxSize(425,400));
    this -> SetSizer(topSizer);

}

void ActivityView::updateView() {
}

void ActivityView::attachView() {
    activityViewed -> subscribeView(this);
}

void ActivityView::detachView() {
    activityViewed -> unsubscribeView(this);
}

ActivityView::~ActivityView() {
    activityViewed -> unsubscribeView(this);
}

void ActivityView::createViewText() {

    activityType = new wxStaticText(this, 2, activityViewed -> getType());
    activityType -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    activityDescription = new wxStaticText(this, 1, activityViewed -> getDescription());
    activityDescription -> SetFont(wxFont(15,wxROMAN, wxNORMAL, wxNORMAL));

    durationString = activityViewed -> getTimeSet() -> startingHour + std::string(":") +
                     activityViewed -> getTimeSet() -> startingMin + std::string("   ") +
                     activityViewed -> getTimeSet() -> finishingHour + std::string (":") +
                     activityViewed -> getTimeSet() -> finishingMin;

    activityDuration = new wxStaticText(this, 3,"Duration: " + durationString);
    activityDuration -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

}

void ActivityView::assembleMenuBar() {

    editField = new wxMenu;
    editField -> Append(5, "&Modify", "Change info about this activity");
    editField -> Append(6, "&Delete", "Delete this activity");

    activityMenuBar = new wxMenuBar;
    activityMenuBar -> Append(editField, "Edit");
    SetMenuBar(activityMenuBar);

}

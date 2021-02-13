//
// Created by redi on 12/02/21.
//

#include "ActivityView.h"


ActivityView::ActivityView(std::shared_ptr<Activity> newActivity): wxFrame(nullptr, wxID_ANY, "Activity Visual"),
                activityViewed(std::move(newActivity)) {

    attachView();

    createViewText();

    windowSizer = new wxBoxSizer(wxVERTICAL);
    this -> SetSizer(windowSizer);

    windowSizer -> Add(activityType, 0, wxEXPAND | wxALL, 20);
    windowSizer -> Add(activityDescription, 0, wxEXPAND | wxALL, 20);
    windowSizer -> Add(activityDuration, 0, wxEXPAND | wxALL, 20);


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

    durationString = std::to_string(activityViewed -> getStartingTime() -> tm_hour) + std::string(":") +
                     std::to_string(activityViewed -> getStartingTime() -> tm_min) + std::string("   ") +
                     std::to_string(activityViewed -> getFinishingTime() -> tm_hour) + std::string (":") +
                     std::to_string(activityViewed -> getFinishingTime() -> tm_min);

    activityDuration = new wxStaticText(this, 3,"Duration: " + durationString);
    activityDuration -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

}

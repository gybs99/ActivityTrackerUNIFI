//
// Created by redi on 12/02/21.
//

#include "ActivityView.h"

wxBEGIN_EVENT_TABLE(ActivityView, wxFrame)
    EVT_MENU(ID_Delete, ActivityView::onDelete)
    EVT_MENU(ID_Modify, ActivityView::onModify)
    EVT_BUTTON(ID_OKButton, ActivityView::onOK)
    EVT_CLOSE(ActivityView::onClose)
wxEND_EVENT_TABLE()


ActivityView::ActivityView(wxFrame* registerView, std::shared_ptr<Activity> newActivity, std::shared_ptr<ActivityTrackerController> newController): wxFrame(registerView, wxID_ANY,
                      "Activity Visual", wxDefaultPosition, wxSize(600,400)), activityViewed(std::move(newActivity)),
                      controller(std::move(newController)){

    ActivityView :: attachView();

    assembleMenuBar();

    this -> CreateStatusBar();

    createViewText();

    this -> SetStatusText("Activity registered the " + std::to_string(activityViewed -> getTimeSet() -> day) + "/" +
                    std::to_string(activityViewed -> getTimeSet() -> month) + "/" + std::to_string(activityViewed ->
                    getTimeSet() -> year));

    backButton = new wxButton(this, ID_OKButton, "OK");

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

    activityType -> SetLabel(activityViewed -> getType());
    activityDescription -> SetLabel(activityViewed -> getDescription());
    generateDurationString();
    activityDuration -> SetLabel("Duration: " + durationString);

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

    generateDurationString();

    activityDuration = new wxStaticText(this, 3,"Duration: " + durationString);
    activityDuration -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

}

void ActivityView::assembleMenuBar() {

    editField = new wxMenu;
    editField -> Append(ID_Modify, "&Modify", "Change info about this activity");
    editField -> Append(ID_Delete, "&Delete", "Delete this activity");

    activityMenuBar = new wxMenuBar;
    activityMenuBar -> Append(editField, "Edit");
    SetMenuBar(activityMenuBar);

}

void ActivityView::onClose(wxCloseEvent &event) {

    m_parent -> Enable(true);
    this -> Destroy();

}

void ActivityView::onOK(wxCommandEvent &event) {

    m_parent -> Enable(true);
    this -> Destroy();

}

void ActivityView::onDelete(wxCommandEvent& wxCommandEvent) {

    controller -> removeActivity(activityViewed);
    wxMessageBox(wxT("Activity successfully deleted"), wxT(""), wxOK | wxICON_INFORMATION);
    m_parent -> Enable(true);
    this -> Destroy();

}

void ActivityView::onModify(wxCommandEvent& event) {

    modifyView = new AddNewActivityView(this, controller, activityViewed);
    modifyView -> Show();
    this -> Enable(false);

}

void ActivityView::generateDurationString() {

    durationString = activityViewed -> getTimeSet() -> startingHour + std::string(":") +
                     activityViewed -> getTimeSet() -> startingMin + std::string("   ") +
                     activityViewed -> getTimeSet() -> finishingHour + std::string (":") +
                     activityViewed -> getTimeSet() -> finishingMin;

}

const std::shared_ptr<ActivityTrackerController> &ActivityView::getController() const {
    return controller;
}

const std::shared_ptr<Activity> &ActivityView::getActivityViewed() const {
    return activityViewed;
}

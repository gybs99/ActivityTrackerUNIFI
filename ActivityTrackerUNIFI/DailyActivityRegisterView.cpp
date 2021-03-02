//
// Created by redi on 22/02/21.
//

#include "DailyActivityRegisterView.h"

wxBEGIN_EVENT_TABLE(DailyActivityRegisterView, wxFrame)
    EVT_LISTBOX_DCLICK(ID_ActivityList, DailyActivityRegisterView::onClickingActivity)
    EVT_BUTTON(ID_AddActivityButton, DailyActivityRegisterView::onAddActivity)
    EVT_CLOSE(DailyActivityRegisterView::onClose)
wxEND_EVENT_TABLE()

DailyActivityRegisterView::DailyActivityRegisterView(wxFrame* mainMenu,
                                                     std::shared_ptr<DailyActivityRegister> newRegisterViewed,
                                                     std::shared_ptr<ActivityTrackerController> newController) :
                                                     wxFrame(mainMenu, wxID_ANY, "Register"),
                                                     registerViewed(std::move(newRegisterViewed)), controller(std::move(newController)) {

    this -> SetMinSize(wxSize(600,350));
    this -> SetTitle(std::to_string(registerViewed -> getDate() -> day) + "/" + std::to_string(registerViewed -> getDate() -> month) + "/" +
                     std::to_string(registerViewed -> getDate() -> year));

    DailyActivityRegisterView :: attachView();
    assembleRegisterView();

}

DailyActivityRegisterView::DailyActivityRegisterView(wxFrame *mainMenu,
                                                     std::shared_ptr<ActivityTrackerController> newController): wxFrame(mainMenu, wxID_ANY, "Register"),
                                                     controller(std::move(newController))
{

    this -> SetMinSize(wxSize(600,350));
    this -> SetTitle("History");

    viewSizer = new wxBoxSizer(wxVERTICAL);
    listSizer = new wxBoxSizer(wxHORIZONTAL);

    listOfActivity = new wxListBox(this, ID_ActivityList, wxDefaultPosition);
    listOfActivity -> Bind(wxEVT_LISTBOX_DCLICK, &DailyActivityRegisterView::onClickingDate, this, ID_ActivityList);
    createRegisterList();
    listSizer -> Add(listOfActivity,1, wxEXPAND);

    infoText = new wxStaticText(this, wxID_ANY, "    Double click a date to display corresponding register!");
    infoText -> SetFont(wxFont(15,wxROMAN, wxNORMAL, wxNORMAL));

    addButton = new wxButton(this, ID_AddActivityButton, "Add Activity");


    viewSizer -> Add(listSizer, 1, wxEXPAND | wxALL, 20);
    viewSizer -> Add(infoText, 1, wxALL);
    viewSizer -> Add(addButton, 0, wxCENTER | wxBOTTOM, 20);

    addButton -> Enable(false);

    this -> SetSizer(viewSizer);

}

void DailyActivityRegisterView::updateView() {

    int actualFields = listOfActivity->GetCount();

    for (int i = actualFields - 1; i>=0 ; i--) {
        listOfActivity -> Delete(i);
    }
    createActivityList();
}

void DailyActivityRegisterView::attachView() {
    registerViewed -> subscribeView(this);
}

void DailyActivityRegisterView::detachView() {
    registerViewed -> unsubscribeView(this);
}

void DailyActivityRegisterView::assembleRegisterView() {

    viewSizer = new wxBoxSizer(wxVERTICAL);
    listSizer = new wxBoxSizer(wxHORIZONTAL);

    listOfActivity = new wxListBox(this, ID_ActivityList, wxDefaultPosition);
    createActivityList();

    listSizer -> Add(listOfActivity,1, wxEXPAND);

    infoText = new wxStaticText(this, wxID_ANY, "    Double click an activity to display it!");
    infoText -> SetFont(wxFont(15,wxROMAN, wxNORMAL, wxNORMAL));

    addButton = new wxButton(this, ID_AddActivityButton, "Add Activity");

    viewSizer -> Add(listSizer, 1, wxEXPAND | wxALL, 20);
    viewSizer -> Add(infoText, 1, wxALL);
    viewSizer -> Add(addButton, 0, wxCENTER | wxBOTTOM, 20);

    this -> SetSizer(viewSizer);


}

void DailyActivityRegisterView::createActivityList() {

    for (const auto& itr : registerViewed -> getListOfActivity()) {

        listOfActivity -> Append(itr.second->getType() + "    " + itr.second->getTimeSet()->startingHour+ ":" +
                            itr.second->getTimeSet()->startingMin + "  " + itr.second->getTimeSet()->finishingHour + ":" +
                            itr.second->getTimeSet()->finishingMin);

    }

}

void DailyActivityRegisterView::onClose(wxCloseEvent& event) {

    if (registerViewed)
    {
        detachView();

        if (controller -> getTodayRegister() -> getListOfActivity().empty()) {
            controller -> removeRegister();
        }

        m_parent -> Enable(true);
        this -> Destroy();
    }
    else
    {
        m_parent -> Enable(true);
        this -> Destroy();
    }
}

void DailyActivityRegisterView::onClickingActivity(wxCommandEvent &event) {

    activityDisplayed = new ActivityView(this, controller -> getActivitySelected(listOfActivity->GetSelection()), controller);
    activityDisplayed -> Show();

}

void DailyActivityRegisterView::onAddActivity(wxCommandEvent &event) {

    addActivityView = new AddNewActivityView(this, controller);
    addActivityView->Show();
    this->Enable(false);

}

void DailyActivityRegisterView::createRegisterList() {

    for (const auto& itr : controller -> getLoadedHistory() -> getHistory()) {

        listOfActivity -> Append(std::to_string(itr -> getDate() -> day) + "/" + std::to_string(itr -> getDate() -> month) + "/" +
                                 std::to_string(itr -> getDate() -> year));

    }

}

void DailyActivityRegisterView::onClickingDate(wxCommandEvent& event) {

    int dateSelected = listOfActivity -> GetSelection();

    registerViewed = controller -> getRegisterSelected(listOfActivity -> GetString(dateSelected).ToStdString());

    DailyActivityRegisterView :: attachView();
    updateView();

    this -> SetTitle(std::to_string(registerViewed -> getDate() -> day) + "/" + std::to_string(registerViewed -> getDate() -> month) + "/" +
                     std::to_string(registerViewed -> getDate() -> year));

    infoText -> SetLabel("    Double click an activity to display it!");

    listOfActivity -> Bind(wxEVT_LISTBOX_DCLICK, &DailyActivityRegisterView::onClickingActivity, this, ID_ActivityList);

    addButton -> Enable(true);

}



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

    attachView();
    assembleView();

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

void DailyActivityRegisterView::assembleView() {

    viewSizer = new wxBoxSizer(wxVERTICAL);
    listSizer = new wxBoxSizer(wxHORIZONTAL);

    listOfActivity = new wxListBox(this, ID_ActivityList, wxDefaultPosition);
    createActivityList();

    listSizer -> Add(listOfActivity,1, wxEXPAND);

    addButton = new wxButton(this, ID_AddActivityButton, "Add Activity");

    viewSizer -> Add(listSizer, 1, wxEXPAND | wxALL, 20);
    viewSizer -> Add(addButton, 0, wxCENTER | wxALL, 20);

    this -> SetSizer(viewSizer);


}

void DailyActivityRegisterView::createActivityList() {

    for (auto itr : registerViewed -> getListOfActivity()) {

        listOfActivity -> Append(itr.second->getType() + "    " + itr.second->getTimeSet()->startingHour+ ":" +
                            itr.second->getTimeSet()->startingMin + "  " + itr.second->getTimeSet()->finishingHour + ":" +
                            itr.second->getTimeSet()->finishingMin);

    }

}

void DailyActivityRegisterView::onClose(wxCloseEvent& event) {

    detachView();
    m_parent -> Enable(true);
    this -> Destroy();

}

void DailyActivityRegisterView::onClickingActivity(wxCommandEvent &event) {

    activityDisplayed = new ActivityView(this, controller -> getActivitySelected(listOfActivity->GetSelection()));
    activityDisplayed -> Show();

}

void DailyActivityRegisterView::onAddActivity(wxCommandEvent &event) {

    addActivityView = new AddNewActivityView(this, controller);
    addActivityView->Show();
    this->Enable(false);

}

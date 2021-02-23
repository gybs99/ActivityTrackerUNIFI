//
// Created by redi on 22/02/21.
//

#include "DailyActivityRegisterView.h"

DailyActivityRegisterView::DailyActivityRegisterView(wxFrame* mainMenu, std::shared_ptr<DailyActivityRegister> newRegisterViewed) :
                                wxFrame(mainMenu, wxID_ANY, "Register"), registerViewed(std::move(newRegisterViewed)) {

    attachView();
    assembleView();

}

void DailyActivityRegisterView::updateView() {

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

    listOfActivity = new wxListBox(this, wxID_ANY, wxDefaultPosition);
    createActivityList();

    listSizer -> Add(listOfActivity,1, wxEXPAND);

    addButton = new wxButton(this, wxID_ANY, "Add Activity");

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

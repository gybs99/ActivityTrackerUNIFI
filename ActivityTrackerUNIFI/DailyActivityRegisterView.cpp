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
    this -> SetTitle(std::to_string(registerViewed -> getRegisterDate().getDay()) + "/" + std::to_string(registerViewed -> getRegisterDate().getMonth()) + "/" +
                     std::to_string(registerViewed -> getRegisterDate().getYear()));

    DailyActivityRegisterView :: attachView();
    assembleRegisterView();

}

DailyActivityRegisterView::DailyActivityRegisterView(wxFrame *mainMenu,
                                                     std::shared_ptr<ActivityTrackerController> newController): wxFrame(mainMenu, wxID_ANY, "Register"),
                                                     controller(std::move(newController))
{

    this -> SetMinSize(wxSize(600,350));
    this -> SetTitle("History");
    assembleHistoryView();
    this -> SetSizer(viewSizer);

}

void DailyActivityRegisterView::updateView() {

    int actualFields = listOfEntries->GetCount();

    for (int i = actualFields - 1; i>=0 ; i--) {
        listOfEntries -> Delete(i);
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

    listOfEntries = new wxListBox(this, ID_ActivityList, wxDefaultPosition);
    createActivityList();

    listSizer -> Add(listOfEntries, 1, wxEXPAND);

    infoText = new wxStaticText(this, wxID_ANY, "    Double click an activity to display it!");
    infoText -> SetFont(wxFont(15,wxROMAN, wxNORMAL, wxNORMAL));

    addButton = new wxButton(this, ID_AddActivityButton, "Add Activity");

    viewSizer -> Add(listSizer, 1, wxEXPAND | wxALL, 20);
    viewSizer -> Add(infoText, 1, wxALL);
    viewSizer -> Add(addButton, 0, wxCENTER | wxBOTTOM, 20);

    this -> SetSizer(viewSizer);


}

void DailyActivityRegisterView::createActivityList() {

    for (int registerPos = 0; registerPos < registerViewed -> getNumberOfActivity(); ++registerPos) {

        listOfEntries -> Append(registerViewed -> findActivity(registerPos) -> getType() + "    " + registerViewed -> findActivity(registerPos) ->
                getDateAndDuration().getStartingHour() + ":" + registerViewed->findActivity(registerPos) -> getDateAndDuration().getStartingMin() +
                "  " + registerViewed -> findActivity(registerPos) -> getDateAndDuration().getFinishingHour() + ":" +
                registerViewed->findActivity(registerPos) -> getDateAndDuration().getFinishingMin());

    }

}

void DailyActivityRegisterView::onClose(wxCloseEvent& event) {

    if (registerViewed)
    {
        detachView();

        if (controller -> getTodayRegister() -> isListOfActivityEmpty()) {
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

    if (controller -> getActivitySelected(listOfEntries -> GetSelection()))
    {
        activityDisplayed = new ActivityView(this, controller->getActivitySelected(listOfEntries->GetSelection()),
                                             controller);
        activityDisplayed->Show();
    }
    else
    {
        wxMessageBox(wxT("An error has occurred during the displaying of this activity. \n Probably the activity selected is missing"),
                     wxT("Warning"), wxOK | wxICON_INFORMATION);
    }

}

void DailyActivityRegisterView::onAddActivity(wxCommandEvent &event) {

    addActivityView = new AddNewActivityView(this, controller);
    addActivityView->Show();
    this->Enable(false);

}

void DailyActivityRegisterView::createRegisterList() {

    for (int registerPos = 0; registerPos < controller -> getHistoryDimension(); ++registerPos) {

        std::shared_ptr<DailyActivityRegister> registerTook = controller -> getRegisterSelected(registerPos);

        if (registerTook)
            listOfEntries -> Append(std::to_string(registerTook -> getRegisterDate().getDay()) + "/" + std::to_string(registerTook -> getRegisterDate().getMonth()) + "/" +
                                std::to_string(registerTook -> getRegisterDate().getYear()));
        else
        {
            wxMessageBox(wxT("An error has occurred during the displaying of the register's date \n Some dates could be missed!"),
            wxT("Warning"), wxOK | wxICON_INFORMATION);
        }
    }

}

void DailyActivityRegisterView::onClickingDate(wxCommandEvent& event) {

    int dateSelected = listOfEntries -> GetSelection();

    registerViewed = controller -> getRegisterSelected(listOfEntries -> GetString(dateSelected).ToStdString());

    if(registerViewed)
    {
        DailyActivityRegisterView :: attachView();
        updateView();

        this -> SetTitle(std::to_string(registerViewed -> getRegisterDate().getDay()) + "/" + std::to_string(registerViewed -> getRegisterDate().getMonth()) + "/" +
                         std::to_string(registerViewed -> getRegisterDate().getYear()));

        infoText -> SetLabel("    Double click an activity to display it!");

        listOfEntries -> Bind(wxEVT_LISTBOX_DCLICK, &DailyActivityRegisterView::onClickingActivity, this, ID_ActivityList);

        addButton -> Enable(true);
    }
    else
    {
        wxMessageBox(wxT("An error has occurred during the date selection. Please retry or restart the app"),
                     wxT("Warning"), wxOK | wxICON_EXCLAMATION);
        m_parent -> Enable(true);
        this -> Destroy();
    }

}

void DailyActivityRegisterView::assembleHistoryView() {

    viewSizer = new wxBoxSizer(wxVERTICAL);
    listSizer = new wxBoxSizer(wxHORIZONTAL);

    listOfEntries = new wxListBox(this, ID_ActivityList, wxDefaultPosition);
    listOfEntries -> Bind(wxEVT_LISTBOX_DCLICK, &DailyActivityRegisterView::onClickingDate, this, ID_ActivityList);
    createRegisterList();
    listSizer -> Add(listOfEntries, 1, wxEXPAND);

    infoText = new wxStaticText(this, wxID_ANY, "    Double click a date to display corresponding register!");
    infoText -> SetFont(wxFont(15,wxROMAN, wxNORMAL, wxNORMAL));

    addButton = new wxButton(this, ID_AddActivityButton, "Add Activity");


    viewSizer -> Add(listSizer, 1, wxEXPAND | wxALL, 20);
    viewSizer -> Add(infoText, 1, wxALL);
    viewSizer -> Add(addButton, 0, wxCENTER | wxBOTTOM, 20);

    addButton -> Enable(false);

}

wxListBox *DailyActivityRegisterView::getListOfEntries() const {
    return listOfEntries;
}



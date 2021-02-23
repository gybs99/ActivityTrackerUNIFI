//
// Created by redi on 10/02/21.
//

#include "MainMenu.h"
#include <ctime>

wxBEGIN_EVENT_TABLE(MainMenu, wxFrame)
    EVT_MENU(ID_About, MainMenu::onInfo)
    EVT_MENU(ID_AddActivity, MainMenu::onAddActivityMenu)
    EVT_MENU(ID_Today, MainMenu::onToday)
    EVT_BUTTON(ID_SignInButton, MainMenu::onSignInButton)
wxEND_EVENT_TABLE()

MainMenu::MainMenu(std::shared_ptr<ActivityTrackerController> newController)
                            : wxFrame(nullptr, wxID_ANY, "Activity Tracker",
                              wxPoint(30, 30), wxSize(650,450), wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER), controller(std::move(newController)) {

    assembleMenuBar();                   // creates the menu bar

    this -> CreateStatusBar();
    this -> SetStatusText("Have a wonderful day!");                        // sets status bar

    setStaticText();                    // add intro text

    lookTodayButton = new wxButton(this, ID_SignInButton, "Sign it!");        // adds the button for new task

    setBoxSizer();

}

void MainMenu::assembleMenuBar() {

    registerField = new wxMenu;
    registerField -> Append(ID_LookRegister, "&Display", "Display your activity list day by day.");
    registerField -> AppendSeparator();
    registerField -> Append(ID_SearchDay, "&Search by day" , "Display activities you've done in a particular day.");

    todayField = new wxMenu;
    todayField -> Append(ID_Today, "&Display", "Display what you've done today.");
    todayField -> AppendSeparator();
    todayField -> Append(ID_AddActivity, "&Add activity", "Sign up a new activity for today.");

    aboutField = new wxMenu;
    aboutField -> Append(ID_About, "&Info" , "Info about the development.");

    mainMenuBar = new wxMenuBar;
    mainMenuBar -> Append(registerField, "&Register");
    mainMenuBar -> Append(todayField, "&Today");
    mainMenuBar -> Append(aboutField, "&About");
    SetMenuBar(mainMenuBar);

}

void MainMenu::setStaticText() {

    introText = new wxStaticText(this, wxID_ANY, "Welcome, here you'll find a  \n list of your daily done tasks!");
    introText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    time_t currentTime = time(nullptr);
    struct tm* timeStruct = localtime((&currentTime));

    dayText = new wxStaticText(this, wxID_ANY, "Today is " + std::to_string(timeStruct->tm_mday) + '/' +
                                               std::to_string(timeStruct->tm_mon + 1) + '/' + std::to_string(timeStruct->tm_year + 1900));
    dayText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    lookTodayText = new wxStaticText(this, wxID_ANY, "Have you done some important today? \n Sign it in your diary!");
    lookTodayText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

}

void MainMenu::setBoxSizer() {

    mainMenuSizer = new wxBoxSizer(wxVERTICAL);

    mainMenuSizer -> Add(introText, 0, wxEXPAND | wxALL, 20);
    mainMenuSizer -> Add(dayText, 0 , wxEXPAND | wxALL, 20);
    mainMenuSizer -> Add(lookTodayText, 0 , wxEXPAND | wxALL, 20);
    mainMenuSizer -> Add(lookTodayButton, 0, wxCENTER, 20);

    this -> SetSizer(mainMenuSizer);
}

void MainMenu::onInfo(wxCommandEvent& event) {
    wxMessageBox(wxT("This program is made by Redi Niccolò"),
                 wxT("Development Info"), wxOK | wxICON_INFORMATION, this);
}

void MainMenu::onSignInButton(wxCommandEvent &event) {

    addActivityView = new AddNewActivityView(this, controller);
    addActivityView -> Show();
    this -> Enable(false);

}

void MainMenu::onAddActivityMenu(wxCommandEvent &event) {

    addActivityView = new AddNewActivityView(this, controller);
    addActivityView -> Show();
    this -> Enable(false);

}

void MainMenu::onToday(wxCommandEvent &event) {

    if(controller -> getTodayRegister() != nullptr) {

        dailyRegisterView = new DailyActivityRegisterView(this, controller->getTodayRegister(), controller);
        dailyRegisterView -> Show();
        this -> Enable(false);

    }
    else {

        wxMessageDialog emptyRegisterDialog(this, wxT("You don't add any done activity for today! \n Do you want to create a new one?"),
                                        wxT("Warning: "), wxYES_NO | wxICON_EXCLAMATION);
        int choice = emptyRegisterDialog.ShowModal();

        if(choice == wxID_YES) {

            addActivityView = new AddNewActivityView(this, controller);
            addActivityView->Show();
            this->Enable(false);

        }

    }
}

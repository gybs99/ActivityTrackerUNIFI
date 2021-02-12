//
// Created by redi on 10/02/21.
//

#include "MainMenu.h"
#include <ctime>

wxBEGIN_EVENT_TABLE(MainMenu, wxFrame)
    EVT_MENU(ID_About, MainMenu::OnInfo)
wxEND_EVENT_TABLE()

MainMenu::MainMenu() : wxFrame(nullptr, wxID_ANY, "Activity Tracker", wxPoint(30, 30),
                               wxSize(650,450), wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER) {

    assembleMenuBar();                   // creates the menu bar

    CreateStatusBar();
    SetStatusText("Have a wonderful day!");                        // sets status bar

    setStaticText();                    // add intro text

    lookTodayButton = new wxButton(this, 1, "Sign it!");        // adds the button for new task

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
    struct tm* timeStruct = localtime((&currentTime));    // Memory leak?

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

void MainMenu::OnInfo(wxCommandEvent& event) {
    wxMessageBox(wxString("This program is made by Redi Niccolò"),
                 wxString("Development Info"), wxOK | wxICON_INFORMATION);      // Need to fix it!
}

//
// Created by redi on 10/02/21.
//

#include "MainMenu.h"
#include <ctime>

MainMenu::MainMenu() : wxFrame(nullptr, wxID_ANY, "Activity Tracker", wxPoint(30, 30),
                               wxSize(650,450), wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER) {

    registerField = new wxMenu;
    registerField -> Append(1000, "&Display");
    registerField -> AppendSeparator();
    registerField -> Append(1001, "&Search by day");

    todayField = new wxMenu;
    todayField -> Append(1000, "&Display");
    todayField -> AppendSeparator();
    todayField -> Append(1001, "&Add activity");

    aboutField = new wxMenu;
    aboutField -> Append(1000, "&Info");

    mainMenuBar = new wxMenuBar;
    mainMenuBar -> Append(registerField, "&Register");
    mainMenuBar -> Append(todayField, "&Today");
    mainMenuBar -> Append(aboutField, "&About");
    SetMenuBar(mainMenuBar);
    CreateStatusBar();
    SetStatusText("Have a wonderful day!");

    mainMenuSizer = new wxBoxSizer(wxVERTICAL);

    introText = new wxStaticText(this, wxID_ANY, "Welcome, here you'll find a  \n list of your daily done tasks!");
    introText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    time_t currentTime = time(nullptr);
    struct tm* timeStruct = localtime((&currentTime));    // Memory leak?

    dayText = new wxStaticText(this, wxID_ANY, "Today is " + std::to_string(timeStruct->tm_mday) + '/' +
                                std::to_string(timeStruct->tm_mon + 1) + '/' + std::to_string(timeStruct->tm_year + 1900));
    dayText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    lookTodayText = new wxStaticText(this, wxID_ANY, "Have you done some important today? \n Sign it in your diary!");
    lookTodayText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    lookTodayButton = new wxButton(this, 1, "Sign it!");

    mainMenuSizer -> Add(introText, 0, wxEXPAND | wxALL, 20);
    mainMenuSizer -> Add(dayText, 0 , wxEXPAND | wxALL, 20);
    mainMenuSizer -> Add(lookTodayText, 0 , wxEXPAND | wxALL, 20);
    mainMenuSizer -> Add(lookTodayButton, 0, wxCENTER, 20);

    this -> SetSizer(mainMenuSizer);
}

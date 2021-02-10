//
// Created by redi on 10/02/21.
//

#include "MainMenu.h"
#include <ctime>

MainMenu::MainMenu() : wxFrame(nullptr, wxID_ANY, "Activity Tracker", wxPoint(30, 30),
                               wxSize(800,600)) {

    registerField = new wxMenu;
    registerField -> Append(1000, "&Display");
    registerField -> AppendSeparator();
    registerField -> Append(1001, "&Search by day");

    mainMenuBar = new wxMenuBar;
    mainMenuBar -> Append(registerField, "&Register");
    SetMenuBar(mainMenuBar);
    CreateStatusBar();
    SetStatusText("Have a wonderful day!");

    mainMenuSizer = new wxBoxSizer(wxVERTICAL);

    introText = new wxStaticText(this, wxID_ANY, "Welcome, here you'll find a list of your daily tasks!");
    introText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));

    time_t currentTime = time(nullptr);
    struct tm* timeStruct = localtime((&currentTime));

    dayText = new wxStaticText(this, wxID_ANY, "Today is " + std::to_string(timeStruct->tm_mday) + '/' +
                                std::to_string(timeStruct->tm_mon + 1) + '/' + std::to_string(timeStruct->tm_year + 1900));
    dayText -> SetFont(wxFont(20,wxROMAN, wxNORMAL, wxNORMAL));


    mainMenuSizer -> Add(introText, 0, wxEXPAND | wxALL, 20);
    mainMenuSizer -> Add(dayText, 0 , wxEXPAND | wxALL, 20);

    this -> SetSizer(mainMenuSizer);
}

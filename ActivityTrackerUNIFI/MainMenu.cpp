//
// Created by redi on 10/02/21.
//

#include "MainMenu.h"

MainMenu::MainMenu() : wxFrame(nullptr, wxID_ANY, "Activity Tracker", wxPoint(30, 30), wxSize(800,600)) {

    mainMenuSizer = new wxBoxSizer(wxHORIZONTAL);

    introText = new wxStaticText(this, wxID_ANY, "Welcome, here you'll find a list of your daily tasks");
    mainMenuSizer -> Add(introText, 0, wxEXPAND);

    this -> SetSizer(mainMenuSizer);
}

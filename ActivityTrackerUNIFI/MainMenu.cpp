//
// Created by redi on 10/02/21.
//

#include "MainMenu.h"

MainMenu::MainMenu() : wxFrame(nullptr, wxID_ANY, "Menu Principale", wxPoint(30, 30), wxSize(800,600)) {

    mainMenuSizer = new wxBoxSizer(wxHORIZONTAL);
    this -> SetSizer(mainMenuSizer);
}

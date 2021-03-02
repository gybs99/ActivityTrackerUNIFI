//
// Created by redi on 22/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTERVIEW_H
#define ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTERVIEW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


#include "ActivityTrackerController.h"
#include "Observer.h"
#include "DailyActivityRegister.h"
#include "ActivityView.h"
#include "AddNewActivityView.h"

enum
{
    ID_ActivityList = 1,
    ID_AddActivityButton = 2
};


class DailyActivityRegisterView : public wxFrame ,public Observer {

public:

    DailyActivityRegisterView(wxFrame* mainMenu, std::shared_ptr<DailyActivityRegister> registerViewed,
                              std::shared_ptr<ActivityTrackerController> newController);

    DailyActivityRegisterView(wxFrame* mainMenu, std::shared_ptr<ActivityTrackerController> newController);

    void assembleRegisterView();

    void createActivityList();

    void createRegisterList();

    void updateView() override;

    void attachView() override;

    void detachView() override;

    void onClose(wxCloseEvent& event);

    void onClickingActivity(wxCommandEvent& event);

    void onAddActivity(wxCommandEvent& event);

    void onClickingDate(wxCommandEvent& event);

private:

    wxBoxSizer* viewSizer {nullptr};
    wxBoxSizer* listSizer {nullptr};

    wxListBox* listOfActivity {nullptr};
    wxButton* addButton {nullptr};
    wxStaticText* infoText {nullptr};

    std::shared_ptr<DailyActivityRegister> registerViewed {nullptr};
    std::shared_ptr<ActivityTrackerController> controller {nullptr};

    ActivityView* activityDisplayed {nullptr};
    AddNewActivityView* addActivityView {nullptr};

    wxDECLARE_EVENT_TABLE();
};


#endif //ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTERVIEW_H

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

enum
{
    ID_ActivityList = 1
};


class DailyActivityRegisterView : public wxFrame ,public Observer {

public:

    DailyActivityRegisterView(wxFrame* mainMenu, std::shared_ptr<DailyActivityRegister> registerViewed,
                              std::shared_ptr<ActivityTrackerController> newController);

    void assembleView();

    void createActivityList();

    void updateView() override;

    void attachView() override;

    void detachView() override;

    void onClose(wxCloseEvent& event);

    void onClickingActivity(wxCommandEvent& event);

private:

    wxBoxSizer* viewSizer {nullptr};
    wxBoxSizer* listSizer {nullptr};

    wxListBox* listOfActivity {nullptr};
    wxButton* addButton {nullptr};

    std::shared_ptr<DailyActivityRegister> registerViewed {nullptr};
    std::shared_ptr<ActivityTrackerController> controller {nullptr};

    ActivityView* activityDisplayed {nullptr};

    wxDECLARE_EVENT_TABLE();
};


#endif //ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTERVIEW_H

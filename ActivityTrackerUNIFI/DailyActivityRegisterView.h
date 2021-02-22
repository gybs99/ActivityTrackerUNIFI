//
// Created by redi on 22/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTERVIEW_H
#define ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTERVIEW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Observer.h"
#include "DailyActivityRegister.h"

class DailyActivityRegisterView : public wxFrame ,public Observer {

public:

    DailyActivityRegisterView();

    void assembleView();

    void updateView() override;

    void attachView() override;

    void detachView() override;

private:

    wxBoxSizer* viewSizer {nullptr};
    wxBoxSizer* listSizer {nullptr};

    wxListBox* listOfActivity {nullptr};
    wxButton* addButton {nullptr};

    std::shared_ptr<DailyActivityRegister> registerViewed {nullptr};

};


#endif //ACTIVITYTRACKERUNIFI_DAILYACTIVITYREGISTERVIEW_H

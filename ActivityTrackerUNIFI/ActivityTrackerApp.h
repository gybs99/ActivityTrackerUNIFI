//
// Created by redi on 10/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERAPP_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERAPP_H

#include <iostream>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class ActivityTrackerApp : public wxApp {
public:
    ActivityTrackerApp();
    bool OnInit() override;
private:

};

#endif //ACTIVITYTRACKERUNIFI_ACTIVITYTRACKERAPP_H

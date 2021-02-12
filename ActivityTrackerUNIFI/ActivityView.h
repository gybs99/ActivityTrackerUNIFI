//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "Observer.h"
#include "Activity.h"
#include <memory>

class ActivityView : public wxFrame, public Observer {

public:
    ActivityView(std::shared_ptr<Activity> newActivity);

    ~ActivityView() override;

    ActivityView(ActivityView&) = delete;

    ActivityView& operator=(const ActivityView) = delete;

    void updateView() override;

    void attachView() override;

    void detachView() override;



private:
    std::shared_ptr<Activity> activityViewed;

    wxStaticText* description;
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H

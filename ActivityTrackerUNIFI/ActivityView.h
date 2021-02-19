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
    explicit ActivityView(std::shared_ptr<Activity> newActivity);

    ~ActivityView() override;

    ActivityView(ActivityView&) = delete;

    ActivityView& operator=(const ActivityView) = delete;

    void updateView() override;

    void attachView() override;

    void detachView() override;

    void createViewText();

    void assembleMenuBar();

private:
    std::shared_ptr<Activity> activityViewed;
    std::string durationString;

    wxStaticText* activityDescription {nullptr};
    wxStaticText* activityType {nullptr};
    wxStaticText* activityDuration {nullptr};

    wxMenu* editField {nullptr};
    wxMenuBar* activityMenuBar {nullptr};

    wxButton* backButton {nullptr};
    wxBoxSizer* topSizer;
    wxBoxSizer* bottomSizer;
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H

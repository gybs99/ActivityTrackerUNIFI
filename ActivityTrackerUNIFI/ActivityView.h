//
// Created by redi on 12/02/21.
//

#ifndef ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H
#define ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H

#include <memory>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Observer.h"
#include "Activity.h"
#include "ActivityTrackerController.h"

enum
{
    ID_OKButton = 1,
    ID_Delete = 2
};


class ActivityView : public wxFrame, public Observer {

public:
    explicit ActivityView(wxFrame* registerView, std::shared_ptr<Activity> newActivity, std::shared_ptr<ActivityTrackerController> newController);

    ~ActivityView() override;

    ActivityView(ActivityView&) = delete;

    ActivityView& operator=(const ActivityView) = delete;

    void updateView() override;

    void attachView() override;

    void detachView() override;

    void createViewText();

    void assembleMenuBar();

    void onClose(wxCloseEvent& event);

    void onOK(wxCommandEvent& event);

    void onDelete(wxCommandEvent& event);

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

    std::shared_ptr<ActivityTrackerController> controller {nullptr};

    wxDECLARE_EVENT_TABLE();
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H

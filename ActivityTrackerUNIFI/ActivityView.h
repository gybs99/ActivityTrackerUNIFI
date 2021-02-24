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

enum
{
    ID_OKButton = 1
};


class ActivityView : public wxFrame, public Observer {

public:
    explicit ActivityView(wxFrame* registerView, std::shared_ptr<Activity> newActivity);

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

    wxDECLARE_EVENT_TABLE();
};


#endif //ACTIVITYTRACKERUNIFI_ACTIVITYVIEW_H

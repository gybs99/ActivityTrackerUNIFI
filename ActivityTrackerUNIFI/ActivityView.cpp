//
// Created by redi on 12/02/21.
//

#include "ActivityView.h"


ActivityView::ActivityView(std::shared_ptr<Activity> newActivity): wxFrame(nullptr, wxID_ANY, "Activity Visual"),
                activityViewed(std::move(newActivity)) {

    attachView();
    description = new wxStaticText(this, 1, activityViewed -> getDescription());
}

void ActivityView::updateView() {

}

void ActivityView::attachView() {
    activityViewed -> subscribeView(this);
}

void ActivityView::detachView() {
    activityViewed -> unsubscribeView(this);
}

ActivityView::~ActivityView() {
    activityViewed -> unsubscribeView(this);
}

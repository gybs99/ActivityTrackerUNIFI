//
// Created by redi on 27/02/21.
//

#include "gtest/gtest.h"
#include "../AddNewActivityView.h"
#include "../ActivityTrackerHistory.h"
#include "wx/uiaction.h"

class TestApp : public wxApp {

public:

    std::shared_ptr<ActivityTrackerController> controller;
    std::shared_ptr<ActivityTrackerHistory> history;

    bool OnInit() override {

        history = std::make_shared<ActivityTrackerHistory>();
        controller = std::make_shared<ActivityTrackerController>(history);
        return true;

    }

};

class GUIFixture : public ::testing::Test {

protected:

    TestApp* testApp;
    void SetUp() override
    {
        char appname[] = "ActivityFunctionTest.exe";
        int argc = 1;
        char* argv[1] = {appname};
        testApp = new TestApp();
        wxApp::SetInstance(testApp);
        wxEntryStart(argc, argv);
        testApp -> OnInit();
    }

    void TearDown() override
    {
        testApp -> OnExit();
        wxEntryCleanup();
    }

};



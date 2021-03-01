//
// Created by redi on 27/02/21.
//

#include "gtest/gtest.h"
#include "../AddNewActivityView.h"
#include "wx/uiaction.h"

class TestApp : public wxApp {

public:

    std::shared_ptr<ActivityTrackerController> controller;

    virtual bool OnInit() {

        controller = std::make_shared<ActivityTrackerController>();
        return true;

    }

};

class GUIFixture : public ::testing::Test {

protected:
    TestApp* testApp;
    virtual void SetUp()
    {
        char appname[] = "ActivityFunctionTest.exe";
        int argc = 1;
        char* argv[1] = {appname};
        testApp = new TestApp();
        wxApp::SetInstance(testApp);
        wxEntryStart(argc, argv);
        testApp -> OnInit();
    }

    virtual void TearDown()
    {
        testApp -> OnExit();
        wxEntryCleanup();
    }

};



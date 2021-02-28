//
// Created by redi on 27/02/21.
//

#include "gtest/gtest.h"
#include "../AddNewActivityView.h"
#include "wx/uiaction.h"

class TestApp : public wxApp {

public:

    AddNewActivityView* editActivityTest;
    std::shared_ptr<ActivityTrackerController> controller;

    virtual bool OnInit() {

        controller = std::make_shared<ActivityTrackerController>();
        return true;

    }

};

class GuiTest : public ::testing::Test {

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

TEST_F(GuiTest, CreateActivityForm)
{

    testApp -> editActivityTest = new AddNewActivityView(nullptr, testApp -> controller);
    testApp -> editActivityTest -> Show();

    testApp -> editActivityTest -> getTypeChoiceList() -> SetValue("Work");
    testApp -> editActivityTest -> getDescriptionTextBox() -> SetValue("Test Description");
    testApp -> editActivityTest -> getStartingHourList() -> SetValue("00");
    testApp -> editActivityTest -> getStartingMinList() -> SetValue("00");
    testApp -> editActivityTest -> getFinishingHourList() -> SetValue("00");
    testApp -> editActivityTest -> getFinishingMinList() -> SetValue("01");



    testApp -> editActivityTest -> getController() -> createActivity(testApp -> editActivityTest -> getTypeChoiceList() -> GetValue().ToStdString(),
                                                      testApp -> editActivityTest -> getDescriptionTextBox() -> GetValue().ToStdString(),
                                                      testApp -> editActivityTest -> getStartingMinList() -> GetValue().ToStdString(),
                                                      testApp -> editActivityTest -> getStartingHourList() -> GetValue().ToStdString(),
                                                      testApp -> editActivityTest -> getFinishingMinList() -> GetValue().ToStdString(),
                                                      testApp -> editActivityTest -> getFinishingHourList() -> GetValue().ToStdString());

    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getType(), "Work");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDescription(), "Test Description");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> startingMin, "00");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> startingHour, "00");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> finishingMin, "01");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> finishingHour, "00");

}

TEST_F(GuiTest, ModifyActivityForm)
{
    testApp -> controller -> createActivity("Work", "Test Description to modify", "00", "00", "01", "00");

    testApp -> editActivityTest = new AddNewActivityView(nullptr, testApp -> controller, testApp -> controller -> getManagedActivity());
    testApp -> editActivityTest -> Show();

    testApp -> editActivityTest -> getDescriptionTextBox() -> SetValue("Test Description modified");

    std::shared_ptr<Activity> activityTest = testApp -> controller -> getManagedActivity();

    testApp -> controller -> modifyActivity(activityTest, testApp -> editActivityTest -> getTypeChoiceList() -> GetValue().ToStdString(),
                                            testApp -> editActivityTest -> getDescriptionTextBox() -> GetValue().ToStdString(),
                                            testApp -> editActivityTest -> getStartingMinList() -> GetValue().ToStdString(),
                                            testApp -> editActivityTest -> getStartingHourList() -> GetValue().ToStdString(),
                                            testApp -> editActivityTest -> getFinishingMinList() -> GetValue().ToStdString(),
                                            testApp -> editActivityTest -> getFinishingHourList() -> GetValue().ToStdString());

    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDescription(), "Test Description modified");

}

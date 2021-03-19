//
// Created by redi on 01/03/21.
//

#include "gtest/gtest.h"
#include "GUIFixture.cpp"
#include "../ActivityView.h"
#include "../DailyActivityRegisterView.h"

class RegisterTestGUIFixture : public GUIFixture {
protected:

    ActivityView* activityTestView {nullptr};
    DailyActivityRegisterView* registerTestView {nullptr};
    std::shared_ptr<Activity> activityTest;
    std::shared_ptr<DailyActivityRegister> registerTest;

    void createActivity() {

        ActivityTime timeTest("00", "00", "01", "00");
        testApp -> controller -> createActivity("Work", "Test Description", timeTest);
        activityTest = testApp -> controller -> getManagedActivity();
        registerTest = testApp -> controller -> getTodayRegister();

    }

    void createBiggerList() {

        createActivity();

        ActivityTime newTimeSet1("01", "00", "02", "00");
        testApp -> controller -> createActivity("Sport", "Test Description 2", newTimeSet1);

        ActivityTime newTimeSet2("02", "00", "03", "00");
        testApp -> controller -> createActivity("Hobby", "Test Description 3", newTimeSet2);

        ActivityTime newTimeSet3("03", "00", "04", "00");
        testApp -> controller -> createActivity("Other", "Test Description 3", newTimeSet3);

        ActivityTime newTimeSet4("04", "00", "05", "00");
        testApp -> controller -> createActivity("Other", "Test Description 4", newTimeSet4);

    }

};

TEST_F(RegisterTestGUIFixture, AddActivityToRegister) {

    createActivity();

    EXPECT_TRUE(!registerTest->isListOfActivityEmpty() );

}

TEST_F(RegisterTestGUIFixture, DeleteAnActivityFromRegister) {

    createActivity();

    activityTestView = new ActivityView(nullptr, activityTest, testApp -> controller);
    std::shared_ptr<Activity> activityFromView = activityTestView -> getActivityViewed();

    activityTestView -> getController() -> removeActivity(activityFromView);

    EXPECT_TRUE(registerTest->isListOfActivityEmpty());

}

TEST_F(RegisterTestGUIFixture, CheckIfViewAttach)
{

    createActivity();

    registerTestView = new DailyActivityRegisterView(nullptr, registerTest, testApp -> controller);

    EXPECT_EQ(registerTest -> getNumberOfViews(), 1);

}

TEST_F(RegisterTestGUIFixture, CheckIfViewDetach)
{
    createActivity();

    registerTestView = new DailyActivityRegisterView(nullptr, registerTest, testApp -> controller);

    registerTestView -> detachView();

    EXPECT_EQ(registerTest -> getNumberOfViews(), 0);

}

TEST_F(RegisterTestGUIFixture, CheckNotifyChangeToViews)
{
    createActivity();

    registerTestView = new DailyActivityRegisterView(nullptr, registerTest, testApp -> controller);

    ActivityTime timeTest("00", "00", "01", "00");

    testApp -> controller -> modifyActivity(activityTest, "Sport", "Test Description", timeTest);

    EXPECT_EQ(registerTestView -> getListOfEntries() -> GetString(0).ToStdString(), "Sport    00:00  00:01");

}

TEST_F(RegisterTestGUIFixture, ModifyActivityInABiggerList)
{
    createBiggerList();
    registerTestView = new DailyActivityRegisterView(nullptr, registerTest, testApp -> controller);

    std::shared_ptr<Activity> activitySelected = testApp -> controller -> getActivitySelected(2);

    ActivityTime newTimeSet2("02", "00", "03", "00");
    testApp -> controller -> modifyActivity(activitySelected, "Sport", "Text Changed", newTimeSet2);

    EXPECT_EQ(registerTestView -> getListOfEntries() -> GetString(2).ToStdString(), "Sport    00:02  00:03");
}

TEST_F(RegisterTestGUIFixture, DeleteAnActivityInABiggerList)
{
    createBiggerList();
    registerTestView = new DailyActivityRegisterView(nullptr, registerTest, testApp -> controller);

    std::shared_ptr<Activity> activitySelected = testApp -> controller -> getActivitySelected(2);
    testApp -> controller -> removeActivity(activitySelected);

    EXPECT_EQ(registerTestView -> getListOfEntries() -> GetString(2).ToStdString(), "Other    00:03  00:04");
}

TEST_F(RegisterTestGUIFixture, DeleteAnInexistentActivity)
{
    createActivity();

    ActivityTime timeTest("00", "00", "00", "01");
    std::shared_ptr<Activity> activityToDelete = std::make_shared<Activity>("Work", "Test Description", timeTest);

    bool result = testApp -> controller -> removeActivity(activityToDelete);

    EXPECT_EQ(result, false);

}

TEST_F(RegisterTestGUIFixture, TryToTakeAnInexistentActivity)
{
    createActivity();

    ASSERT_TRUE(testApp -> controller -> getActivitySelected(0) != nullptr);
    ASSERT_TRUE(testApp -> controller -> getActivitySelected(1) == nullptr);
}

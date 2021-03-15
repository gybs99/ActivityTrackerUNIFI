//
// Created by redi on 15/02/21.
//
#include "gtest/gtest.h"
#include "GUIFixture.cpp"

class ActivityTestGUIFixture : public GUIFixture {

protected:
    AddNewActivityView* editActivityTest {nullptr};

};


TEST(Activity, StandardActivityConstruction)        // It sees if the Date with constructor is equal with the system one
{                                                   // and if all the given parameters are OK
    ActivityTime timeTest("10", "10", "30", "10");

    Activity activityTest("Sport", "I've done some running", timeTest);

    ASSERT_EQ(timeTest.getYear(), activityTest.getDateAndDuration().getYear());
    ASSERT_EQ(timeTest.getMonth(), activityTest.getDateAndDuration().getMonth());
    ASSERT_EQ(timeTest.getDay(), activityTest.getDateAndDuration().getDay());
    ASSERT_EQ("10", activityTest.getDateAndDuration().getStartingMin());
    ASSERT_EQ("10", activityTest.getDateAndDuration().getStartingHour());
    ASSERT_EQ("30", activityTest.getDateAndDuration().getFinishingMin());
    ASSERT_EQ("10", activityTest.getDateAndDuration().getFinishingHour());

}

TEST_F(ActivityTestGUIFixture, CreateActivityForm)
{

    editActivityTest = new AddNewActivityView(nullptr, testApp -> controller);
    editActivityTest -> Show();

    editActivityTest -> getTypeChoiceList() -> SetValue("Work");
    editActivityTest -> getDescriptionTextBox() -> SetValue("Test Description");
    editActivityTest -> getStartingHourList() -> SetValue("00");
    editActivityTest -> getStartingMinList() -> SetValue("00");
    editActivityTest -> getFinishingHourList() -> SetValue("00");
    editActivityTest -> getFinishingMinList() -> SetValue("01");

    ActivityTime timeTest(editActivityTest -> getStartingMinList() -> GetValue().ToStdString(),
                          editActivityTest -> getStartingHourList() -> GetValue().ToStdString(),
                          editActivityTest -> getFinishingMinList() -> GetValue().ToStdString(),
                          editActivityTest -> getFinishingHourList() -> GetValue().ToStdString());

    editActivityTest -> getController() -> createActivity(editActivityTest -> getTypeChoiceList() -> GetValue().ToStdString(),
                                                          editActivityTest -> getDescriptionTextBox() -> GetValue().ToStdString(), timeTest);

    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getType(), "Work");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDescription(), "Test Description");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDateAndDuration().getStartingMin(), "00");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDateAndDuration().getStartingHour(), "00");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDateAndDuration().getFinishingMin(), "01");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDateAndDuration().getFinishingHour(), "00");

}

TEST_F(ActivityTestGUIFixture, ModifyActivityForm)
{
    ActivityTime timeTest("00", "00", "01", "00");

    testApp -> controller -> createActivity("Work", "Test Description to modify", timeTest);

    editActivityTest = new AddNewActivityView(nullptr, testApp -> controller, testApp -> controller -> getManagedActivity());
    editActivityTest -> Show();

    editActivityTest -> getDescriptionTextBox() -> SetValue("Test Description modified");

    std::shared_ptr<Activity> activityTest = testApp -> controller -> getManagedActivity();

    ActivityTime newTimeSet(editActivityTest -> getStartingMinList() -> GetValue().ToStdString(),
                            editActivityTest -> getStartingHourList() -> GetValue().ToStdString(),
                            editActivityTest -> getFinishingMinList() -> GetValue().ToStdString(),
                            editActivityTest -> getFinishingHourList() -> GetValue().ToStdString());

    testApp -> controller -> modifyActivity(activityTest, editActivityTest -> getTypeChoiceList() -> GetValue().ToStdString(),
                                            editActivityTest -> getDescriptionTextBox() -> GetValue().ToStdString(), newTimeSet);

    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDescription(), "Test Description modified");

}

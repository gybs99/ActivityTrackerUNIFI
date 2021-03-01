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
    time_t currentTime = time(nullptr);
    struct tm* currentSystemDate = localtime(&currentTime);

    Activity activityTest("Sport", "I've done some running",
                                          "10", "10", "30", "10");

    ASSERT_EQ(currentSystemDate->tm_year + 1900, activityTest.getTimeSet() -> year);
    ASSERT_EQ(currentSystemDate -> tm_mon + 1, activityTest.getTimeSet() -> month);
    ASSERT_EQ(currentSystemDate -> tm_mday, activityTest.getTimeSet() -> day);
    ASSERT_EQ("10", activityTest.getTimeSet() -> startingMin);
    ASSERT_EQ("10", activityTest.getTimeSet() -> startingHour);
    ASSERT_EQ("30", activityTest.getTimeSet() -> finishingMin);
    ASSERT_EQ("10", activityTest.getTimeSet() -> finishingHour);

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



    editActivityTest -> getController() -> createActivity(editActivityTest -> getTypeChoiceList() -> GetValue().ToStdString(),
                                                          editActivityTest -> getDescriptionTextBox() -> GetValue().ToStdString(),
                                                          editActivityTest -> getStartingMinList() -> GetValue().ToStdString(),
                                                          editActivityTest -> getStartingHourList() -> GetValue().ToStdString(),
                                                          editActivityTest -> getFinishingMinList() -> GetValue().ToStdString(),
                                                          editActivityTest -> getFinishingHourList() -> GetValue().ToStdString());

    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getType(), "Work");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDescription(), "Test Description");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> startingMin, "00");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> startingHour, "00");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> finishingMin, "01");
    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getTimeSet() -> finishingHour, "00");

}

TEST_F(ActivityTestGUIFixture, ModifyActivityForm)
{
    testApp -> controller -> createActivity("Work", "Test Description to modify", "00", "00", "01", "00");

    editActivityTest = new AddNewActivityView(nullptr, testApp -> controller, testApp -> controller -> getManagedActivity());
    editActivityTest -> Show();

    editActivityTest -> getDescriptionTextBox() -> SetValue("Test Description modified");

    std::shared_ptr<Activity> activityTest = testApp -> controller -> getManagedActivity();

    testApp -> controller -> modifyActivity(activityTest, editActivityTest -> getTypeChoiceList() -> GetValue().ToStdString(),
                                            editActivityTest -> getDescriptionTextBox() -> GetValue().ToStdString(),
                                            editActivityTest -> getStartingMinList() -> GetValue().ToStdString(),
                                            editActivityTest -> getStartingHourList() -> GetValue().ToStdString(),
                                            editActivityTest -> getFinishingMinList() -> GetValue().ToStdString(),
                                            editActivityTest -> getFinishingHourList() -> GetValue().ToStdString());

    ASSERT_EQ(testApp -> controller -> getManagedActivity() -> getDescription(), "Test Description modified");

}

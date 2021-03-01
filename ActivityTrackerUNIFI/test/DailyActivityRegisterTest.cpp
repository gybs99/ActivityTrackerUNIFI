//
// Created by redi on 01/03/21.
//

#include "gtest/gtest.h"
#include "GUIFixture.cpp"
#include "../ActivityView.h"

class RegisterTestGUIFixture : public GUIFixture {
protected:

    ActivityView* activityTestView;
    std::shared_ptr<Activity> activityTest;
    std::shared_ptr<DailyActivityRegister> registerTest;
    int firstElementID = 0;                                     //In the activity list, the first activity added will have this value of ID, so we want to check if it will be present on the list

    void createActivity() {


        testApp -> controller -> createActivity("Work", "Test Description", "00", "00", "01", "00");
        activityTest = std::move(testApp -> controller -> getManagedActivity());
        registerTest = std::move(testApp -> controller -> getTodayRegister());
    }

};

TEST_F(RegisterTestGUIFixture, AddActivityToRegister) {

    createActivity();

    EXPECT_TRUE(registerTest -> getListOfActivity().find(firstElementID) != registerTest -> getListOfActivity().end() );

}

TEST_F(RegisterTestGUIFixture, DeleteAnActivityFromRegister) {

    createActivity();

    activityTestView = new ActivityView(nullptr, activityTest, testApp -> controller);
    std::shared_ptr<Activity> activityFromView = std::move(activityTestView -> getActivityViewed());

    activityTestView -> getController() -> removeActivity(activityFromView);

    EXPECT_TRUE(registerTest -> getListOfActivity().find(0) == registerTest -> getListOfActivity().end());

}
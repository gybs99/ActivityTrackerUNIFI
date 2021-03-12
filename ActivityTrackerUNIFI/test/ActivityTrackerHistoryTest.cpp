//
// Created by redi on 03/03/21.
//
#include "gtest/gtest.h"
#include "GUIFixture.cpp"
#include "../DailyActivityRegisterView.h"

class HistoryTestFixture : public GUIFixture {

protected:

    std::shared_ptr<DailyActivityRegister> registerTest;
    DailyActivityRegisterView* historyView {nullptr};

    int registerTestDay;
    int registerTestMonth;
    int registerTestYear;

    void createActivity() {

        testApp -> controller -> createActivity("Work", "Test Description", "00", "00", "01", "00");
        registerTest = testApp -> controller -> getTodayRegister();

    };

    void getRegisterDateInfo() {

        registerTestDay = registerTest -> getRegisterDate().getDay();
        registerTestMonth = registerTest -> getRegisterDate().getMonth();
        registerTestYear = registerTest -> getRegisterDate().getYear();

    }

};

TEST_F(HistoryTestFixture, AddRegisterTest) {

    createActivity();
    getRegisterDateInfo();

    historyView = new DailyActivityRegisterView(nullptr, testApp -> controller);
    historyView -> Show();

    ASSERT_TRUE(historyView -> getListOfActivity() -> GetCount() != 0);
    ASSERT_EQ(testApp -> controller -> getLoadedHistory() -> searchRegister(registerTestDay, registerTestMonth, registerTestYear), registerTest);

}

TEST_F(HistoryTestFixture, RemoveRegisterTest) {

    createActivity();
    getRegisterDateInfo();

    testApp -> controller -> removeRegister();

    historyView = new DailyActivityRegisterView(nullptr, testApp -> controller);
    historyView -> Show();

    ASSERT_TRUE(historyView -> getListOfActivity() -> GetCount() == 0);
    ASSERT_EQ(testApp -> controller -> getLoadedHistory() -> searchRegister(registerTestDay, registerTestMonth, registerTestYear), nullptr);

}

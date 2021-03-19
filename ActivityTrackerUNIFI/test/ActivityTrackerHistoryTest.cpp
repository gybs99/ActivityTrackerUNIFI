//
// Created by redi on 03/03/21.
//
#include "gtest/gtest.h"
#include "GUIFixture.cpp"
#include "../DailyActivityRegisterView.h"
#include "../MainMenu.h"

class HistoryTestFixture : public GUIFixture {

protected:

    std::shared_ptr<DailyActivityRegister> registerTest;
    DailyActivityRegisterView* historyView {nullptr};
    MainMenu* menuTest {nullptr};

    int registerTestDay;
    int registerTestMonth;
    int registerTestYear;

    void createActivity() {

        ActivityTime timeTest("00", "00", "01", "00");
        testApp -> controller -> createActivity("Work", "Test Description", timeTest);
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

    ASSERT_TRUE(historyView->getListOfEntries() -> GetCount() != 0);
    ASSERT_EQ(testApp -> controller -> searchRegister(registerTestDay, registerTestMonth, registerTestYear), registerTest);

}

TEST_F(HistoryTestFixture, RemoveRegisterTest) {

    createActivity();
    getRegisterDateInfo();

    testApp -> controller -> removeRegister();

    historyView = new DailyActivityRegisterView(nullptr, testApp -> controller);

    ASSERT_TRUE(historyView->getListOfEntries() -> GetCount() == 0);
    ASSERT_EQ(testApp -> controller -> searchRegister(registerTestDay, registerTestMonth, registerTestYear), nullptr);

}

TEST_F(HistoryTestFixture, DisplayHistoryInfo) {

    createActivity();
    getRegisterDateInfo();

    historyView = new DailyActivityRegisterView(nullptr, testApp -> controller);

    std::string actualDate = std::to_string(registerTestDay) + "/" + std::to_string(registerTestMonth) + "/" +
            std::to_string(registerTestYear);

    ASSERT_EQ(historyView -> getListOfEntries() -> GetString(0), actualDate);

}

TEST_F(HistoryTestFixture, IfEmptyHistoryDeleted) {

    menuTest = new MainMenu(testApp -> controller);

    createActivity();

    auto registerTestView = new DailyActivityRegisterView(menuTest, testApp -> controller -> getTodayRegister(),
                                                                                testApp -> controller);

    testApp -> controller -> removeActivity(testApp -> controller -> getManagedActivity());

    registerTestView -> Close();

    ASSERT_EQ(testApp -> controller -> getHistoryDimension(), 0);

}

TEST_F(HistoryTestFixture, ViewAnInexistentDate)
{
    createActivity();

    historyView = new DailyActivityRegisterView(nullptr, testApp -> controller);

    ASSERT_TRUE(testApp -> controller -> getRegisterSelected("99/99/99") == nullptr);
    ASSERT_TRUE(testApp -> controller -> getRegisterSelected(historyView -> getListOfEntries() -> GetString(0).ToStdString()) != nullptr);

}

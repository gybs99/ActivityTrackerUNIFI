//
// Created by redi on 15/02/21.
//
#include "gtest/gtest.h"
#include "../Activity.h"
#include <ctime>

TEST(Activity, StandardActivityConstruction)        // It sees if the Date with constructor is equal with the system one
{                                                   // and if all the given parameters are OK
    time_t currentTime = time(nullptr);
    struct tm* currentSystemDate = localtime(&currentTime);

    Activity activityTest("Sport", "I've done some running",
                                          10, 10, 30, 10);

    ASSERT_EQ(currentSystemDate->tm_year + 1900, activityTest.getTimeSet() -> year);
    ASSERT_EQ(currentSystemDate -> tm_mon + 1, activityTest.getTimeSet() -> month);
    ASSERT_EQ(currentSystemDate -> tm_mday, activityTest.getTimeSet() -> day);
    ASSERT_EQ(10, activityTest.getTimeSet() -> startingMin);
    ASSERT_EQ(10, activityTest.getTimeSet() -> startingHour);
    ASSERT_EQ(30, activityTest.getTimeSet() -> finishingMin);
    ASSERT_EQ(10, activityTest.getTimeSet() -> finishingHour);

}

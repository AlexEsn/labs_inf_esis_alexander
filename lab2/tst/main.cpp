#include "gtest/gtest.h"
#include <QApplication>
#include <QPushButton>


TEST(lol, kek){
    EXPECT_TRUE(1);
    EXPECT_FALSE(1);
    ASSERT_TRUE(1);
    ASSERT_FALSE(1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
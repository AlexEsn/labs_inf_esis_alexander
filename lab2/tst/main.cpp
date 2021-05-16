#include "gtest/gtest.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
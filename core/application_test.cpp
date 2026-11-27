#include "core/application.h"

#include <gtest/gtest.h>

TEST(ApplicationTest, checkDefaultStatus) {
    EXPECT_EQ(jobtracker::Application().status, jobtracker::Status::Applied);
}
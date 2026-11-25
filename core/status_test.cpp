#include "core/status.h"

#include <gtest/gtest.h>

TEST(StatusTest, TestStatusToString) {
    EXPECT_EQ("Applied", jobtracker::to_string(jobtracker::Status::Applied));
}


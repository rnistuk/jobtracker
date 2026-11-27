#include "core/application.h"
#include "core/status.h"

#include <gtest/gtest.h>
#include <type_traits>

static_assert(std::is_aggregate_v<jobtracker::Application>,
                "Application must stay an aggregate so designated initializers work");

TEST(ApplicationTest, DefaultStatus) {
    EXPECT_EQ(jobtracker::Application().status, jobtracker::Status::Applied);
}

TEST(ApplicationTest, DefaultDateIsUnset) {
    jobtracker::Application app;
    EXPECT_FALSE(app.date_applied.ok());
}

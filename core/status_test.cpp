#include "core/status.h"
#include <algorithm>
#include <gtest/gtest.h>

struct StatusCase {
    jobtracker::Status status;
    std::string_view text;
};

class StatusToStringTest : public ::testing::TestWithParam<StatusCase> {};

TEST_P(StatusToStringTest, ConvertsToText) {
    EXPECT_EQ(GetParam().text, jobtracker::to_string(GetParam().status));
}



INSTANTIATE_TEST_SUITE_P(AllStatuses, StatusToStringTest, ::testing::Values(
    StatusCase{jobtracker::Status::Applied, "Applied"},
    StatusCase{jobtracker::Status::Pending, "Pending"},
    StatusCase{jobtracker::Status::TechInterview, "Tech Interview"},
    StatusCase{jobtracker::Status::OfferReceived, "Offer Received"},
    StatusCase{jobtracker::Status::OfferAccepted, "Offer Accepted"},
    StatusCase{jobtracker::Status::Rejected, "Rejected"},
    StatusCase{jobtracker::Status::Withdrawn, "Withdrawn"},
    StatusCase{jobtracker::Status::Ghosted, "Ghosted"}
    ),
    [](const ::testing::TestParamInfo<StatusCase>& info) {
        auto s{std::string{info.param.text}};
        std::erase(s, ' ');
        return s;
    }
);

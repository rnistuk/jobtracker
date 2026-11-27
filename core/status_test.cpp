#include "core/status.h"

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

struct StatusCase {
    jobtracker::Status status;
    std::string_view text;
};

class StatusConversionTest : public ::testing::TestWithParam<StatusCase> {};

TEST_P(StatusConversionTest, ConvertsToAndFromText) {
    EXPECT_EQ(GetParam().text, jobtracker::to_string(GetParam().status));
    EXPECT_EQ(GetParam().status, jobtracker::status_from_string(GetParam().text));
}

INSTANTIATE_TEST_SUITE_P(
    AllStatuses, StatusConversionTest,
    ::testing::Values(StatusCase{jobtracker::Status::Applied, "Applied"},
                      StatusCase{jobtracker::Status::TechInterview, "Tech Interview"},
                      StatusCase{jobtracker::Status::OfferReceived, "Offer Received"},
                      StatusCase{jobtracker::Status::OfferAccepted, "Offer Accepted"},
                      StatusCase{jobtracker::Status::Rejected, "Rejected"},
                      StatusCase{jobtracker::Status::Withdrawn, "Withdrawn"},
                      StatusCase{jobtracker::Status::Ghosted, "Ghosted"},
                      StatusCase{jobtracker::Status::HrScreen, "HR Screen"},
                      StatusCase{jobtracker::Status::Interview, "Interview"}),
    [](const ::testing::TestParamInfo<StatusCase>& info) {
        auto s{std::string{info.param.text}};
        std::erase(s, ' ');
        return s;
    });

TEST(AllStatuses, FromStringRejectsUnknownText) {
    EXPECT_EQ(std::nullopt, jobtracker::status_from_string("Invalid"));
}

TEST(AllStatuses, EveryStatusSurvivesRoundTrip) {
    for (int i = 0; i < static_cast<int>(jobtracker::Status::EndSentinel); ++i) {
        auto status{static_cast<jobtracker::Status>(i)};
        auto text{jobtracker::to_string(status)};
        EXPECT_EQ(status, jobtracker::status_from_string(text));
    }
}

TEST(AllStatuses, ToStringThrowsOnEndSentinel) {
    EXPECT_THROW(jobtracker::to_string(jobtracker::Status::EndSentinel), std::logic_error);
}

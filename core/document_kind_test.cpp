#include "core/document_kind.h"

#include <algorithm>
#include <gtest/gtest.h>

struct DocumentKindCase {
    jobtracker::DocumentKind kind;
    std::string_view name;
};

class DocumentKindConversionTest : public ::testing::TestWithParam<DocumentKindCase> {};

TEST_P(DocumentKindConversionTest, ConvertsToAndFromText) {
    EXPECT_EQ(GetParam().name, jobtracker::to_string(GetParam().kind));
    EXPECT_EQ(GetParam().kind, jobtracker::document_kind_from_string(GetParam().name));
}

INSTANTIATE_TEST_SUITE_P(AllDocumentKinds, DocumentKindConversionTest, ::testing::Values(
    DocumentKindCase{jobtracker::DocumentKind::Resume, "Resume"},
    DocumentKindCase{jobtracker::DocumentKind::JobDescription, "Job Description"},
    DocumentKindCase{jobtracker::DocumentKind::CoverLetter, "Cover Letter"},
    DocumentKindCase{jobtracker::DocumentKind::Other, "Other"}
    ),
    [](const ::testing::TestParamInfo<DocumentKindCase>& info) {
        auto s { std::string(info.param.name) };
        std::erase(s, ' ');
        return s;
    }
);

TEST(AllDocumentKinds, FromStringRejectsUnknownText) {
    EXPECT_EQ(std::nullopt, jobtracker::document_kind_from_string("Invalid"));
}

TEST(AllDocumentKinds, EveryDocumentKindSurvivesRoundTrip) {
    for (int i = 0; i < static_cast<int>(jobtracker::DocumentKind::EndSentinel); ++i) {
        auto kind { static_cast<jobtracker::DocumentKind>(i) };
        EXPECT_EQ(kind, jobtracker::document_kind_from_string(jobtracker::to_string(kind)));
    }
}

TEST(AllDocumentKinds, ToStringThrowsOnEndSentinel) {
    EXPECT_THROW(jobtracker::to_string(jobtracker::DocumentKind::EndSentinel), std::logic_error);
}

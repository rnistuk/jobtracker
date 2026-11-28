#include "core/document.h"
#include "core/document_kind.h"

#include <gtest/gtest.h>
#include <type_traits>

static_assert(std::is_aggregate_v<jobtracker::Document>,
              "Document must stay an aggregate so designated initializers work");

TEST(Document, DefaultDocument) {
    jobtracker::Document sut;
    EXPECT_EQ(sut.kind, jobtracker::DocumentKind::Other);
}

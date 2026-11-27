#pragma once

#include <optional>
#include <string_view>

namespace jobtracker {
    enum class DocumentKind { JobDescription, Resume, CoverLetter, Other, EndSentinel };

    std::string_view to_string(const DocumentKind kind);
    std::optional<DocumentKind> document_kind_from_string(const std::string_view text);
} // namespace jobtracker

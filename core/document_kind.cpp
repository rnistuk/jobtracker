#include "core/document_kind.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>

namespace jobtracker {
    namespace {
        struct DocumentKindName {
            DocumentKind kind;
            std::string_view name;
        };

        constexpr auto document_kind_names = std::to_array<DocumentKindName>({
            {DocumentKind::JobDescription, "Job Description"},
            {DocumentKind::Resume, "Resume"},
            {DocumentKind::CoverLetter, "Cover Letter"},
            {DocumentKind::Other, "Other"},
        });
        static_assert(document_kind_names.size() ==
                          static_cast<std::size_t>(DocumentKind::EndSentinel),
                      "document_kind_names is missing an entry");
    } // namespace

    std::string_view to_string(DocumentKind kind) {
        auto it = std::ranges::find(document_kind_names, kind, &DocumentKindName::kind);
        if (it != document_kind_names.end()) {
            return it->name;
        }

        throw std::logic_error("to_string: DocumentKind has no entry in document_kind_names");
    }

    std::optional<DocumentKind> document_kind_from_string(std::string_view text) {
        auto it = std::ranges::find(document_kind_names, text, &DocumentKindName::name);
        if (it != document_kind_names.end())
            return it->kind;
        return std::nullopt;
    }
} // namespace jobtracker

#include "core/status.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>

namespace jobtracker {
    namespace {
        struct StatusName {
            Status status;
            std::string_view name;
        };

        constexpr auto status_names = std::to_array<StatusName>({
            {Status::Applied, "Applied"},
            {Status::HrScreen, "HR Screen"},
            {Status::Interview, "Interview"},
            {Status::TechInterview, "Tech Interview"},
            {Status::OfferReceived, "Offer Received"},
            {Status::OfferAccepted, "Offer Accepted"},
            {Status::Rejected, "Rejected"},
            {Status::Withdrawn, "Withdrawn"},
            {Status::Ghosted, "Ghosted"},
        });
        static_assert(status_names.size() == static_cast<std::size_t>(Status::EndSentinel),
                      "status_names is missing an entry");
    } // namespace

    std::string_view to_string(Status status) {
        auto it = std::ranges::find(status_names, status, &StatusName::status);
        if (it != status_names.end())
            return it->name;

        throw std::logic_error("to_string: Status has no entry in status_names");
    }

    std::optional<Status> status_from_string(std::string_view text) {
        auto it = std::ranges::find(status_names, text, &StatusName::name);
        if (it != status_names.end())
            return it->status;
        return std::nullopt;
    }

} // namespace jobtracker

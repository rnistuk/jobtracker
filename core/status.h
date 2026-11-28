#pragma once

#include <optional>
#include <string_view>

namespace jobtracker {
    enum class Status {
        Applied,
        HrScreen,
        Interview,
        TechInterview,
        OfferReceived,
        OfferAccepted,
        Rejected,
        Withdrawn,
        Ghosted,
        EndSentinel
    };

    std::string_view to_string(Status status);
    std::optional<Status> status_from_string(std::string_view text);

} // namespace jobtracker

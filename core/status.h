#pragma once

#include <optional>
#include <string_view>

namespace jobtracker {
    enum class Status {
        Applied,
        TechInterview,
        OfferReceived,
        OfferAccepted,
        Rejected,
        Withdrawn,
        Ghosted,
        HrScreen,
        Interview,
        EndSentinel
    };

    std::string_view to_string(const Status status);
    std::optional<Status> status_from_string(std::string_view text);

}

#pragma once

#include <optional>
#include <string_view>
#include <utility>

namespace jobtracker {
    enum class Status {
        Applied,
        Pending,
        TechInterview,
        OfferReceived,
        OfferAccepted,
        Rejected,
        Withdrawn,
        Ghosted,
        HrScreen,
        Interview
    };

    std::string_view to_string(const Status status);
    std::optional<Status> from_string(std::string_view text);

}

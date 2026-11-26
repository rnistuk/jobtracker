#pragma once

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
        Ghosted
    };

    constexpr std::string_view to_string(const Status status) {

        switch (status) {
            case Status::Applied:
                return "Applied";
            case Status::Pending:
                return "Pending";
            case Status::TechInterview:
                return "Tech Interview";
            case Status::OfferReceived:
                return "Offer Received";
            case Status::OfferAccepted:
                return "Offer Accepted";
            case Status::Rejected:
                return "Rejected";
            case Status::Withdrawn:
                return "Withdrawn";
            case Status::Ghosted:
                return "Ghosted";
        }
        std::unreachable();
    }

}

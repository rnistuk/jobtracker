#include "status.h"

#include <string>

namespace jobtracker {
    std::string_view to_string(const Status status) {
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
            case Status::HrScreen:
                return "HR Screen";
            case Status::Interview:
                return "Interview";
        }
        std::unreachable();
    }

    std::optional<Status> from_string(std::string_view text) {
        if (text == "Applied") {
            return std::optional<Status>(Status::Applied);
        } else if (text == "Pending") {
            return std::optional<Status>(Status::Pending);
        } else if(text == "Tech Interview") {
            return std::optional<Status>(Status::TechInterview);
        } else if (text == "Offer Received") {
            return std::optional<Status>(Status::OfferReceived);
        } else if (text == "Offer Accepted") {
            return std::optional<Status>(Status::OfferAccepted);
        } else if (text == "Rejected") {
            return std::optional<Status>(Status::Rejected);
        } else if (text == "Withdrawn") {
            return std::optional<Status>(Status::Withdrawn);
        } else if (text == "Ghosted") {
            return std::optional<Status>(Status::Ghosted);
        } else if (text == "HR Screen") {
            return std::optional<Status>(Status::HrScreen);
        } else if (text == "Interview") {
            return std::optional<Status>(Status::Interview);
        }
        return std::nullopt;
    }

}

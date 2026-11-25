#pragma once

#include <string_view>
#include <utility>

namespace jobtracker {
    enum class Status {
        Applied
    };

    constexpr std::string_view to_string(const Status status) {

        switch (status) {
            case Status::Applied:
                return "Applied";
        }
        std::unreachable();
    }

}

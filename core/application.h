#pragma once
#include "core/status.h"

#include <chrono>
#include <string>

namespace jobtracker {

    struct Application {
        std::string company;
        std::string role;
        Status status{Status::Applied};
        std::chrono::year_month_day date_applied{};
    };
} // namespace jobtracker

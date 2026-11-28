#pragma once

#include "core/document_kind.h"

#include <cstddef>
#include <string>
#include <vector>

namespace jobtracker {
    struct Document {
        DocumentKind kind{DocumentKind::Other};
        std::string filename;
        std::vector<std::byte> contents;
    };
} // namespace jobtracker

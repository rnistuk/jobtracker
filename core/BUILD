load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "status",
    srcs = ["status.cpp"],
    hdrs = ["status.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "status_test",
    srcs = ["status_test.cpp"],
    deps = [
        ":status",
        "@googletest//:gtest_main",
    ],
    size = "small",
)

cc_library(
    name = "document_kind",
    srcs = ["document_kind.cpp"],
    hdrs = ["document_kind.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "document_kind_test",
    srcs = ["document_kind_test.cpp"],
    deps = [
        ":document_kind",
        "@googletest//:gtest_main",
    ],
    size = "small",
)


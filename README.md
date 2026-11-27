# jobtracker

A command-line tool for tracking job applications, written in C++23 and backed by SQLite.

> **Work in progress:** the data model is in place; storage and the CLI are not built yet.

## Features

Done:
- Application records: company, role, status, and date applied
- Application statuses, from *Applied* through *Offer Accepted*, plus *Rejected*, *Withdrawn*, and *Ghosted*
- Document kinds: job description, résumé, cover letter, and other

Planned:
- SQLite storage
- Attach documents to an application
- A CLI to add, update, and list applications

## Prerequisites

- [Bazelisk](https://github.com/bazelbuild/bazelisk) (`brew install bazelisk`). It reads `.bazelversion` and uses the pinned Bazel version (9.3.3).
- A C++23 compiler. Tested on macOS with Apple clang 21.

## Build

```sh
bazel build //...
```

## Run

Not yet. The CLI is planned.

## Tests

```sh
bazel test //...
```

## License

MIT. See [LICENSE](LICENSE).

# ThreadPool

A lightweight, efficient C++ thread pool implementation providing a simple API for task submission and safe shutdown. Designed for clarity, performance, and ease of integration into existing C++ projects.

## Features

- Fixed-size thread pool with a task queue
- Safe shutdown and graceful join
- Minimal, header-first API (`ThreadPool.hpp`) and a small implementation file
- Simple CMake-based build and test setup

## Requirements

- C++17 (or newer) compatible compiler (GCC, Clang)
- CMake 4.3.2+

## Building

Clone the repository and build with CMake:

```bash
git clone <repo-url>
cd ThreadPool
mkdir -p build && cd build
cmake ..
```

This produces the example/test executable `threadpool_test` in the `build/` directory.

## Example

A minimal example is provided in `src/main.cpp` and a test runner is available at `build/threadpool_test` when built with CMake.

## API (overview)

- `ThreadPool(size_t numThreads)` — create pool with `numThreads` workers.
- `enqueue(Fn&& f, Args&&... args)` — submit a task and receive a `std::future`.
- `shutdown()` — stops accepting tasks and joins worker threads.

See `src/ThreadPool.hpp` for method signatures and usage details.
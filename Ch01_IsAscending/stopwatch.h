#pragma once

#include <chrono>

class Stopwatch {
    // Ready: Stopwatch is ready to begin timing
    // Running: Timing in progress
    // Stopped: Timing is complete
    enum Status { Ready, Running, Stopped };

    Status status;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> stop_time;
    bool is_running;
public:
    Stopwatch();
    void start();
    void stop();
    // Returns seconds of time elapsed
    double elapsed() const;
    // Resets the stopwatch regardless of its running status
    void reset();

};


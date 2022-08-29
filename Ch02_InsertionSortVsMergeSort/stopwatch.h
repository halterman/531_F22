#pragma once

#include <chrono>

class Stopwatch {
    // Private status type
    // Ready: Stopwatch is ready to begin timing
    // Running: Timing in progress
    // Stopped: Timing is stopped and elapsed time is available
    enum class Status { Ready, Running, Stopped };

    Status status;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> stop_time;
    double elapsed_time;
    bool is_running;
public:
    Stopwatch();

    // Initiates new timing or resumes a paused timing
    // Has no effect if the stopwatch currently is running.
    void start();

    // Stops or pauses a timing
    // Has no effect if the stopwatch is not currently running.
    // The timing may be resumed via the start method without
    // losing any time accumulated while the stopwatch has been 
    // running.
    // Client must call reset on the stopwatch to begin a 
    // a new timing. 
    void stop();

    // Returns seconds of time elapsed while the stopwatch has been running
    double elapsed() const;

    // Resets the stopwatch to its initial state regardless of its 
    // running status. Erases accumulated time, if any.
    void reset();
};


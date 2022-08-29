#include <stdexcept>
#include "stopwatch.h"

// A new stopwatch object is ready to begin timing
Stopwatch::Stopwatch() : status{Status::Ready}, elapsed_time{0.0} {}


// Initiates new timing or resumes a paused timing.
// Has no effect if the stopwatch currently is running.
void Stopwatch::start() {
    if (status != Status::Running) {
        // Begin a new timing or resume the current timing 
        // that the client has paused
        status = Status::Running;
        start_time = std::chrono::high_resolution_clock::now();
    }
}


// Stops or pauses a timing.
// Has no effect if the stopwatch is not currently running.
// The timing may be resumed via the start method without
// losing any time accumulated while the stopwatch has been 
// running.
// Client must call reset on the stopwatch to begin a 
// a new timing. 
void Stopwatch::stop() {
    if (status == Status::Running) {
        stop_time = std::chrono::high_resolution_clock::now();
        status = Status::Stopped;
        // Accumulate time elapsed since last started
        elapsed_time += std::chrono::duration<double, std::milli>
                            (stop_time - start_time).count()/1000.0;
    }
}


// Resets the stopwatch to its initial state regardless of its 
// running status. Erases accumulated time, if any.
void Stopwatch::reset() {
    status = Status::Ready;
    elapsed_time = 0.0;
}


// Returns seconds of time elapsed while the stopwatch has been running
double Stopwatch::elapsed() const {
    if (status != Status::Running)
        return elapsed_time;
    else
        throw std::runtime_error("Attempt to read a running stopwatch");
}


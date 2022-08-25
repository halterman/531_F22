#include "stopwatch.h"

// A new stopwatch object is ready to begin timing
Stopwatch::Stopwatch() : status{Ready} {}

// Has no effect if the stopwatch is not ready to begin timing
void Stopwatch::start() {
    if (status == Ready) {
        status = Running;
        start_time = std::chrono::high_resolution_clock::now();
    }
}

// Has no effect if the stopwatch is not currently running.
// Client must call reset on the stopwatch before a subsequent
// timing. 
void Stopwatch::stop() {
    if (status == Running) {
        stop_time = std::chrono::high_resolution_clock::now();
        status = Stopped;
    }
}

// Makes the stopwatch ready to begin timing.
// Clients must call reset between subsequent timings.
void Stopwatch::reset() {
    status = Ready;
}

// Returns seconds of time elapsed
double Stopwatch::elapsed() const {
    if (status == Stopped)
        return std::chrono::duration<double, std::milli>
               (stop_time - start_time).count()/1000.0;
    else
        return 0;
}


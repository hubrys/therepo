#ifndef SRC_FALLING_SAND_TIME_HPP
#define SRC_FALLING_SAND_TIME_HPP

#include <chrono>

namespace yage {
class Time {
public:
    using Clock = std::chrono::steady_clock;
    using Seconds = std::chrono::duration<float>;

    explicit Time(Seconds fixedDelta);

    void start();

    /*
     * Returns true is we have accumulated enough time for a fixed time step,
     * reduces accumulator by fixed time step
     */
    void accumulate();

    double accumulatedTime() { return accumulatedTime_.count(); }

    /// Do not call this outside of the engine, bad things will happen
    bool consumeFixedDelta();

    [[nodiscard]] float fixedDelta() const { return fixedDeltaRaw_; }

    [[nodiscard]] int fixedSteps() const { return fixedStepCount_; }

private:
    Clock::time_point startTime_;
    Clock::time_point lastTimeSeen_;
    Seconds delta_{};
    Seconds accumulatedTime_{};
    Seconds fixedDelta_;
    float fixedDeltaRaw_;
    int fixedStepCount_ = 0;
};
}


#endif //SRC_FALLING_SAND_TIME_HPP

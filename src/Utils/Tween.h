//
// Created by sw1ssyy on 01/11/2026.
//

#ifndef TOPDOWNSHOOTER_TWEEN
#define TOPDOWNSHOOTER_TWEEN

class Tween
{
public:
    /// @param duration Total time in seconds the tween takes to go from start to end.
    explicit Tween(float duration);

    /// Begins a new tween. Captures the start/end values once and resets the timer.
    void Start(float from, float to, bool loop);

    /// Call once per frame. Adds GetFrameTime() to the timer and recalculates the value.
    void Update();

    /// Stops the tween where it is, keeping the current value.
    void Stop();

    /// Puts the timer back to 0 and the value back to the start value.
    void Reset();

    /// The current interpolated value.
    float GetValue() const;

    /// True once the elapsed time has reached the duration.
    bool IsFinished() const;

    /// True while the tween has been started and has not finished or been stopped.
    bool IsRunning() const;

private:
    float _from = 0.0f;

    float _to = 0.0f;

    float _duration;

    float _elapsed = 0.0f;

    float _value = 0.0f;

    bool _isRunning = false;

    bool _isFinished = false;

    bool _isLooping = false;
};

#endif //TOPDOWNSHOOTER_TWEEN

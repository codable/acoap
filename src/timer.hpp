#ifndef TIMER_HPP_H
#define TIMER_HPP_H

class Timer
{
public:
    typedef void (*Handler)(Timer &aTimer);
    Timer(otInstance &aInstance, Handler aHandler, void* aContext);
    void Start(uint32_t aDelta);
    void Stop(void);
    bool IsRunning(void) const;
    uint32_t GetFireTime(void) const;
    static uint32_t GetNow(void);
    static uint32_t SecToMsec(uint32_t aSeconds);
};

#endif // TIMER_HPP_H

#pragma once


#include <string>
#include <thread>
#include <functional>
#include <chrono>
#include <mutex>
#include <atomic>

class Timer
{
private:
    std::thread timer_;
    std::atomic<bool> isRunning_;

    //member function callback
    std::function<void(void*)> callback_;
    //object that callback_ is called from
    void* callbackObj_;
    
    bool inited_;

    // time in ns that the timer should run for after a restart
    std::chrono::milliseconds duration_;
    // time that the timer will expire at
    std::chrono::time_point<std::chrono::system_clock> expireTime_;
public:
    // this timer class will always call the same callback function
    Timer();

    // Destructor
    virtual ~Timer();

    // set all the parameters. CallbackFunction is a static member function to be called when
    // the timer expires. thisPtr is the object to call callbackFunction() from. duration is the
    // time in ms that the timer should run after being started or extended. 
    void Init(std::function<void(void*)> callbackFunction, void* thisPtr, unsigned int duration);

    // Start starts the timer if it is not running, or extends the timer if it is
    void Start();
};


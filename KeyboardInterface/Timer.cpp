#include "Timer.h"
#include <thread>
#include <chrono>
#include <iostream>


const int SLEEP_PRECISION_MS = 30;

Timer::Timer() : inited_(false), 
                 callbackObj_(nullptr), 
                 callback_(nullptr),
                 isRunning_(false),
                 duration_(std::chrono::milliseconds(0))
{}

void Timer::Init(std::function<void(void*)> callbackFunction, void* thisPtr, unsigned int duration) 
{
    callbackObj_ = thisPtr;
    callback_ = callbackFunction;
    inited_ = true;
    duration_ = std::chrono::milliseconds(duration);
}

void Timer::Start()
{
    if (!inited_)
    {
        std::cerr << "Timer started without initialization" << std::endl;
        return;
    }

    expireTime_ = std::chrono::system_clock::now() + duration_;

    if (!isRunning_)
    {
        timer_ = std::thread([&]
        {
            isRunning_ = true;
            while (true)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_PRECISION_MS));
                if (expireTime_ < std::chrono::system_clock::now())
                {
                    callback_(callbackObj_);
                    timer_.detach();
                    timer_.~thread();
                    isRunning_ = false;
                    break;
                }
            }
        });
    }

}


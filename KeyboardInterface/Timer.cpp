/*
 MIT License

Copyright (c) 2024 Wyatt Lien

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Timer.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <Windows.h>


const int SLEEP_PRECISION_MS = 30;

Timer::Timer() : inited_(false), 
                 callbackObj_(nullptr), 
                 callback_(nullptr),
                 isRunning_(false),
                 duration_(std::chrono::milliseconds(0))
{}

Timer::~Timer()
{
    try
    {
        //only kill the timer when it is not running
        while (isRunning_)
        {
            Sleep(SLEEP_PRECISION_MS);
        }
    }
    catch (...)
    {
        std::cout << "Error in Timer destructor";
        //just continue
    }
}

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


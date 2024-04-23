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


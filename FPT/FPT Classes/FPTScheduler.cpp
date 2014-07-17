//
//  FPTScheduler.cpp
//  FPTSchedulerTest
//
//  Created by Danny van Swieten on 10-07-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "FPTScheduler.h"

FPTScheduler::FPTScheduler()
{
    _currentTime = 0;
}

FPTScheduler::~FPTScheduler()
{
    
}

void FPTScheduler::play()
{

}

void FPTScheduler::addEvent(unsigned long int timeStamp, EventFuntion function, bool repeat)
{
    _timeLine.push_back(FPTEvent(getGurrentTime() + timeStamp, function, repeat));
}

void FPTScheduler::update(unsigned long timeStamp)
{
    _currentTime = timeStamp;
    for(auto& event : _timeLine)
    {
        if(timeStamp >= event.getTimeStamp())
        {
            event.process();
            _timeLine.pop_back();
        }
    }
}
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
    
}

FPTScheduler::~FPTScheduler()
{
    
}

void FPTScheduler::addEvent(unsigned long int timeStamp, EventFuntion function)
{
    _events.push_back(FPTEvent(getGurrentTime() + timeStamp, function));
}

void FPTScheduler::update(unsigned long timeStamp)
{
    _currentTime = timeStamp;
    for(auto& event : _events)
    {
        if(timeStamp >= event.getTimeStamp())
        {
            event.process();
            _events.pop_back();
        }
    }
}
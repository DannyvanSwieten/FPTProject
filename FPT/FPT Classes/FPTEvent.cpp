//
//  FPTEvent.cpp
//  FPTSchedulerTest
//
//  Created by Danny van Swieten on 10-07-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "FPTEvent.h"

FPTEvent::FPTEvent()
{
    _repeat = false;
}

FPTEvent::FPTEvent(unsigned long int timeStamp, EventFunction function, bool repeat)
{
    _repeat = repeat;
    _timeStamp = timeStamp;
    _function = function;
}

FPTEvent::~FPTEvent()
{
    
}

void FPTEvent::process()
{
    _function();
}
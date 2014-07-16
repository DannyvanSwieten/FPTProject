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
    
}

FPTEvent::FPTEvent(unsigned long int timeStamp, EventFunction function)
{
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
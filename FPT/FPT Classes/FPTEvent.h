//
//  FPTEvent.h
//  FPTSchedulerTest
//
//  Created by Danny van Swieten on 10-07-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __FPTSchedulerTest__FPTEvent__
#define __FPTSchedulerTest__FPTEvent__

#include <functional>

using EventFunction = std::function<void()>;

class FPTEvent
{
public:
    FPTEvent();
    FPTEvent(unsigned long int timeStamp, EventFunction function);
    ~FPTEvent();
    
    unsigned long int getTimeStamp(){return _timeStamp;};
    void process();
    
private:
    EventFunction _function;
    unsigned long int _timeStamp;
};

#endif /* defined(__FPTSchedulerTest__FPTEvent__) */

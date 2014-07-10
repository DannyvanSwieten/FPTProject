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

class FPTEvent
{
public:
    FPTEvent();
    FPTEvent(unsigned long int timeStamp, std::function<void()> function);
    ~FPTEvent();
    
    unsigned long int getTimeStamp(){return _timeStamp;};
    void process();
    
private:
    std::function<void()> _execute;
    unsigned long int _timeStamp;
};

#endif /* defined(__FPTSchedulerTest__FPTEvent__) */

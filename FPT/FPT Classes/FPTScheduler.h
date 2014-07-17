//
//  FPTScheduler.h
//  FPTSchedulerTest
//
//  Created by Danny van Swieten on 10-07-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __FPTSchedulerTest__FPTScheduler__
#define __FPTSchedulerTest__FPTScheduler__

#include <vector>
#include "FPTEvent.h"

class FPTScheduler
{
public:
    FPTScheduler();
    ~FPTScheduler();
    
    using EventFuntion = std::function<void()>;
    
    void addEvent(unsigned long int timeStamp, EventFuntion function, bool repeat);
    void update(unsigned long int timeStamp);
    void play();
    void stop();
    
    inline unsigned long int getGurrentTime(){return _currentTime;};
    
private:
    
    std::vector<FPTEvent> _timeLine;
    unsigned long int _currentTime;
};

#endif /* defined(__FPTSchedulerTest__FPTScheduler__) */

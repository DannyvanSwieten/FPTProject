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
    
    void addEvent(FPTEvent event);
    void update(unsigned long int timeStamp);
    
private:
    std::vector<FPTEvent> _events;
};

#endif /* defined(__FPTSchedulerTest__FPTScheduler__) */

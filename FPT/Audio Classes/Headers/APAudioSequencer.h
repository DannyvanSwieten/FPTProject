//
//  APAudioSequencer.h
//  FPT
//
//  Created by Danny van Swieten on 17-07-14.
//
//

#ifndef __FPT__APAudioSequencer__
#define __FPT__APAudioSequencer__

#include "../JuceLibraryCode/JuceHeader.h"
#include "FPTEvent.h"
#include "FPTScheduler.h"
#include <vector>

class APAudioSequencer
{
public:
    APAudioSequencer(FPTScheduler* scheduler);
    virtual ~APAudioSequencer() = 0;
    
    void play();
    void stop();
    void pause();
    void update(unsigned int time);
    using EventFuntion = std::function<void()>;
    void addEvent(unsigned long int timeStamp, EventFuntion function);
    
private:
    
    FPTScheduler* _scheduler;
    std::vector<FPTEvent> _events;
    unsigned long int _currentTime;
    bool _stop;
    bool _pause;
    bool _play;
};
#endif /* defined(__FPT__APAudioSequencer__) */

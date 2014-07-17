//
//  APAudioTransport.h
//  FPT
//
//  Created by Danny van Swieten on 17-07-14.
//
//

#ifndef __FPT__APAudioTransport__
#define __FPT__APAudioTransport__

#include "APAudioSequencer.h"

class APAudioTransport
{
public:
    APAudioTransport();
    
    void update(unsigned int time);
    
    void addTrack(APAudioSequencer track);
    void play();
    void pause();
    void stop();
    
private:
    
    unsigned long int _currentTime;
    std::vector<APAudioSequencer> _tracks;
};

#endif /* defined(__FPT__APAudioTransport__) */

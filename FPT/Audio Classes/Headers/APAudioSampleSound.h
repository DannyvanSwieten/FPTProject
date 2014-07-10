//
//  APAudioSampleSound.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 13-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __APAudioEngine__APAudioSampleSound__
#define __APAudioEngine__APAudioSampleSound__

#include "APAudioSoundDescription.h"
#include "../JuceLibraryCode/JuceHeader.h"

class APAudioSampleSound: public APAudioSoundDescription
{
public:
    
    APAudioSampleSound();
    virtual ~APAudioSampleSound();
    
    void loadFile(String fileName);
    
    bool listensToNote(ControlValue note) override;
    bool listensToChannel(ControlValue channel) override;
    
    void setRange(ControlValue min, ControlValue max);
    
    void updatePosition();
    
    AudioSampleBuffer buffer;
    
    TimerValue grainSize;
    TimerValue hopSize;
    TimerValue currentPosition;
    
    AudioFormatManager formatManager;
    AudioFormatReader* formatReader = nullptr;
    
private:
    
    ControlValue minNote;
    ControlValue maxNote;
    ControlValue channel;
    
    Sample* hann;
};

#endif /* defined(__APAudioEngine__APAudioSampleSound__) */

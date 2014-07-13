//
//  APAudioSoundDescription.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 13-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __APAudioEngine__APAudioSoundDescription__
#define __APAudioEngine__APAudioSoundDescription__

#include "APAudioModule.h"

class APAudioSoundDescription
{
public:
    APAudioSoundDescription();
    
    virtual ~APAudioSoundDescription();
    
    virtual bool    listensToNote(ControlValue note) = 0;
    virtual bool    listensToChannel(ControlValue channel) = 0;
    
    void setData(AudioSampleBuffer audioData);
    
    void            setRange(ControlValue min, ControlValue max);
    
    inline ControlValue getMinNote(){return minNote;};
    inline ControlValue getMaxNote(){return maxNote;};
    inline ControlValue getChannel(){return channel;};
    
    AudioSampleBuffer data;
    
private:
    
    ControlValue minNote;
    ControlValue maxNote;
    ControlValue channel;
};

#endif /* defined(__APAudioEngine__APAudioSoundDescription__) */

//
//  APAudioSampleSound.cpp
//  APAudioEngine
//
//  Created by Danny van Swieten on 13-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "APAudioSampleSound.h"

APAudioSampleSound::APAudioSampleSound(): APAudioSoundDescription()
{
    currentPosition = 0;
    grainSize   = 44 * 500;
    hopSize     = 44 * 500;
    
    hann = new Sample[grainSize];
}

APAudioSampleSound::~APAudioSampleSound()
{
    
}

bool APAudioSampleSound::listensToNote(ControlValue note)
{
    if (note >= getMinNote() && note <= getMaxNote())
        return true;
    else
        return false;
}

bool APAudioSampleSound::listensToChannel(ControlValue channel)
{
    if (getChannel() == channel)
        return true;
    else
        return false;
}
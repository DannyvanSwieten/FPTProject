//
//  APAudioSoundDescription.cpp
//  APAudioEngine
//
//  Created by Danny van Swieten on 13-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "APAudioSoundDescription.h"

APAudioSoundDescription::APAudioSoundDescription()
{
    
}

APAudioSoundDescription::~APAudioSoundDescription()
{
    
}

void APAudioSoundDescription::setData(juce::AudioSampleBuffer audioData)
{
    data = audioData;
}
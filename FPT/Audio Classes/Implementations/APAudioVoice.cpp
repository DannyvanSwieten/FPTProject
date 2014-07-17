//
//  APAudioVoice.
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "APAudioVoice.h"

APAudioVoice::APAudioVoice()
{
    envelope = new APAudioEnvelope();
}

APAudioVoice::~APAudioVoice()
{
    delete sound;
    delete envelope;
}

void APAudioVoice::setIsPlaying(bool playing)
{
    isPlaying = playing;
}

void APAudioVoice::setPitch(ControlValue pitch)
{
    if(pitch == 60)
        this->pitch = 1.0;
    else
        this->pitch = (60.0/pitch) + pow(2, (pitch-60.0)/12);
}

void APAudioVoice::setID(UInt ID)
{
    voiceID = ID;
}

void APAudioVoice::releaseVoice()
{
    isPlaying = false;
}

void APAudioVoice::setSound(APAudioSoundDescription *sound)
{
    this->sound = sound;
}
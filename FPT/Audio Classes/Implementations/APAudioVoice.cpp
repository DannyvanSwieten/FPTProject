//
//  APAudioVoiceCPP.cpp
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "APAudioVoiceCPP.h"

APAudioVoiceCPP::APAudioVoiceCPP()
{
    envelope = new APAudioEnvelope();
}

APAudioVoiceCPP::~APAudioVoiceCPP()
{
    delete sound;
    delete envelope;
}

void APAudioVoiceCPP::setIsPlaying(bool playing)
{
    isPlaying = playing;
}

void APAudioVoiceCPP::setPitch(ControlValue pitch)
{
    this->pitch = pitch;
}

void APAudioVoiceCPP::setID(UInt ID)
{
    voiceID = ID;
}

void APAudioVoiceCPP::releaseVoice()
{
    isPlaying = false;
}

void APAudioVoiceCPP::setSound(APAudioSoundDescription *sound)
{
    this->sound = sound;
}
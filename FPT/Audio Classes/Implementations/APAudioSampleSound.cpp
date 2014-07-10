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
    File::getCurrentWorkingDirectory();
    currentPosition = 0;
    grainSize   = 44 * 500;
    hopSize     = 44 * 500;
    
    hann = new Sample[grainSize];
}

APAudioSampleSound::~APAudioSampleSound()
{
    
}

void APAudioSampleSound::loadFile(String fileName)
{
    if(formatReader == nullptr)
    {
        File file = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile).getChildFile(fileName);
        FileInputStream* stream = file.createInputStream();
        
        if (stream == nullptr)
        {
            std::cout<<"failed"<<std::endl;
            return;
        }
        
        formatManager.registerBasicFormats();
        
        formatReader = formatManager.createReaderFor(file);
        
        buffer.setSize(2, formatReader->lengthInSamples + 10);
        
        formatReader->read(&buffer, 0, formatReader->lengthInSamples, 0, true, true);
    }
}

void APAudioSampleSound::updatePosition()
{
    currentPosition += hopSize;
    
    if (currentPosition + grainSize >= formatReader->lengthInSamples)
    {
        formatReader->read(&buffer, 0, grainSize, currentPosition, true, false);
    }
    else
    {
        formatReader->read(&buffer, 0, grainSize, currentPosition, true, false);
    }
}

void APAudioSampleSound::setRange(ControlValue min, ControlValue max)
{
    minNote = min;
    maxNote = max;
}

bool APAudioSampleSound::listensToNote(ControlValue note)
{
    if (note >= minNote && note <= maxNote)
        return true;
    else
        return false;
}

bool APAudioSampleSound::listensToChannel(ControlValue channel)
{
    if (this->channel == channel)
        return true;
    else
        return false;
}
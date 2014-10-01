//
//  APAudioFile.cpp
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 10/1/14.
//
//

#include "APAudioFile.h"

APAudioFile::~APAudioFile()
{
    
}

void APAudioFile::setAudio(AudioSampleBuffer buffer)
{
    _audio = buffer;
}

void APAudioFile::setNumChannels(int channels)
{
    _numChannels = channels;
}

void APAudioFile::setNumSamples(long int samples)
{
    _numSamples = samples;
};

void APAudioFile::setFileName(String name)
{
    _fileName = name;
}

String APAudioFile::getName()
{
    return _fileName;
}

const float* APAudioFile::getAudioChannel(int index)
{
    return _audio.getReadPointer(index);
}

int APAudioFile::getNumChannels()
{
    return _numChannels;
}

long int APAudioFile::getNumSamples()
{
    return _numSamples;
}
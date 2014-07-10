//
//  APAudioModule.
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "APAudioModule.h"

APAudioMainFrame::APAudioMainFrame(Sample sr, TimerValue bs)
{
    bufferSize = bs;
    sampleRate = sr;
}

APAudioMainFrame::~APAudioMainFrame()
{
    
}

void APAudioMainFrame::addModule(APAudioModule *module)
{
    modules.emplace_back(module);
}

//--------------------Module-------------------------------
APAudioModule::APAudioModule(APAudioMainFrame* mf)
{
    mf->addModule(this);
    bufferSize = mf->getBufferSize();
    sampleRate = mf->getSampleRate();
    
    outputBuffer = new Sample[bufferSize];
    
    prevIndex = 0;
}

void APAudioModule::setID(juce::String ID)
{
    this->ID = ID;
}

APAudioModule::~APAudioModule()
{
    
}

void APAudioModule::connect(APAudioModule *module)
{
    inputList.emplace_back(module);
}

void APAudioModule::calculateBuffer()
{
    
}


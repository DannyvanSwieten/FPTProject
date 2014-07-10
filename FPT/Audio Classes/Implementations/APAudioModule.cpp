//
//  APAudioModuleCPP.cpp
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "APAudioModuleCPP.h"

APAudioMainFrame::APAudioMainFrame(Sample sr, TimerValue bs)
{
    bufferSize = bs;
    sampleRate = sr;
}

APAudioMainFrame::~APAudioMainFrame()
{
    
}

void APAudioMainFrame::addModule(APAudioModuleCPP *module)
{
    modules.emplace_back(module);
}

//--------------------Module-------------------------------
APAudioModuleCPP::APAudioModuleCPP(APAudioMainFrame* mf)
{
    mf->addModule(this);
    bufferSize = mf->getBufferSize();
    sampleRate = mf->getSampleRate();
    
    outputBuffer = new Sample[bufferSize];
    
    prevIndex = 0;
}

void APAudioModuleCPP::setID(juce::String ID)
{
    this->ID = ID;
}

APAudioModuleCPP::~APAudioModuleCPP()
{
    
}

void APAudioModuleCPP::connect(APAudioModuleCPP *module)
{
    inputList.emplace_back(module);
}

void APAudioModuleCPP::calculateBuffer()
{
    
}


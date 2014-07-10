//
//  APAudioModuleCPP.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __APAudioEngine__APAudioModuleCPP__
#define __APAudioEngine__APAudioModuleCPP__

#include <vector>
#include <stdlib.h>
#include <string>
#include <iostream>
//#include "Functions.h"

#include "../JuceLibraryCode/JuceHeader.h"


using Sample        = float;
using SampleBuffer  = float*;
using ControlValue  = double;
using TimerValue     = unsigned int;
using UInt          = unsigned int;

class APAudioModuleCPP;
class APAudioParameterCPP;

class APAudioMainFrame
{
public:
    
    APAudioMainFrame(Sample sr, TimerValue bs);
    virtual ~APAudioMainFrame();
    void addModule(APAudioModuleCPP* module);
    
    inline ControlValue getSampleRate(){return sampleRate;};
    inline TimerValue   getBufferSize(){return bufferSize;};
    
private:
    std::vector<APAudioModuleCPP*> modules;
    ControlValue    sampleRate;
    TimerValue      bufferSize;
};

class APAudioModuleCPP
{
public:
    
    APAudioModuleCPP(APAudioMainFrame* mf);
    virtual ~APAudioModuleCPP();
    virtual void calculateBuffer();
    
    void setID(juce::String ID);
    inline juce::String getID(){return ID;};
    
    inline Sample returnOutputSample(TimerValue index)
    {
        if (index < prevIndex)
        {
            outputSample = outputBuffer[bufferSize - prevIndex + index];
        }
        else
        {
            if (inputList.size() != 0)
            {
            for (auto& input : inputList)
            {
                if (input != NULL)
                {
                    for (auto i = 0; i < bufferSize; i++)
                    {
                        input->outputBuffer[i] = input->returnOutputSample(prevIndex + i);
                    }
                }
            }
            }
            prevIndex = index + bufferSize;
            calculateBuffer();
            outputSample = outputBuffer[bufferSize - prevIndex + index];
        }
        return outputSample;
    };
    
    void   connect(APAudioModuleCPP* module);
    
    inline Sample getSampleRate(){return sampleRate;};
    inline TimerValue getBufferSize(){return bufferSize;};
    
    SampleBuffer    outputBuffer;
    std::vector<APAudioModuleCPP*> inputList;
    std::vector<APAudioParameterCPP*> parameters;
private:
    
    TimerValue  bufferSize;
    TimerValue  prevIndex;
    Sample      sampleRate;
    Sample      outputSample;
    
    SampleBuffer    inputBuffer;
    
    juce::String ID;
};



#endif /* defined(__APAudioEngine__APAudioModuleCPP__) */

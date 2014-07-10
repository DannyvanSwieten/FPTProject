//
//  APAudioParameterCPP.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __APAudioEngine__APAudioParameterCPP__
#define __APAudioEngine__APAudioParameterCPP__

#include "APAudioModuleCPP.h"
#include "../JuceLibraryCode/JuceHeader.h"

class APAudioParameterCPP
{
public:
    
    APAudioParameterCPP(ControlValue min,
                        ControlValue max,
                        ControlValue start,
                        juce::String identification);
    
    void setMinValue(ControlValue value);
    void setMaxValue(ControlValue value);
    void setValue(ControlValue value);
    
    inline ControlValue getMinValue(){return minValue;};
    inline ControlValue getMaxValue(){return maxValue;};
    inline ControlValue getValue(){return currentValue;};
    inline juce::String getID(){return ID;};
    
private:
    
    ControlValue minValue;
    ControlValue maxValue;
    ControlValue currentValue;
    
    juce::String ID;
};

#endif /* defined(__APAudioEngine__APAudioParameterCPP__) */

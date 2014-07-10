//
//  APAudioSamplerVoice.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 08-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef APAudioEngine_APAudioSamplerVoice_h
#define APAudioEngine_APAudioSamplerVoice_h

#include "APAudioVoiceCPP.h"

class APAudioSamplerVoice: public APAudioVoiceCPP
{
public:
    
    APAudioSamplerVoice();
    
    enum class PlaybackMode
    {
        Sampler,
        GrainSampler
    };
    
    void renderNextBlock (SampleBuffer outputBuffer,
                          int startSample,
                          int numSamples,
                          UInt channel) override;
    
    void stopVoice() override;
    
    bool canPlaySound(APAudioSoundDescription* sound) override;
    
    void reset() override;
    
private:
    
    PlaybackMode mode;
    ControlValue idx;
    UInt floorIdx;
    ControlValue frac;
};

#endif

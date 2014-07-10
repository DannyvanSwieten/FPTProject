//
//  APAudioVoiceManagerCPP.h
//  APAudioEngine
//
//  Created by Danny van Swieten on 07-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __APAudioEngine__APAudioVoiceManagerCPP__
#define __APAudioEngine__APAudioVoiceManagerCPP__

#include "APAudioSamplerVoice.h"
#include "APAudioModuleCPP.h"

class APAudioVoiceManager: public APAudioModuleCPP
{
public:
    APAudioVoiceManager(APAudioMainFrame* mf, UInt channel);
    APAudioVoiceCPP* findFreeVoice(APAudioSoundDescription* soundDescription, ControlValue pitch);
    
    void noteOn(ControlValue pitch, ControlValue ID);
    void noteOff(UInt ID);
    void updatePitch(ControlValue pitch, ControlValue ID);
    
    void addSound(APAudioSoundDescription* s);
    
    void startVoice(APAudioVoiceCPP* voice, APAudioSoundDescription* sound, ControlValue pitch, ControlValue velocity);
    void addSamplerVoice();
    void destroyAllVoices();
    
    void calculateBuffer()override;
    
    UInt getActiveVoices();
    
    std::vector<APAudioVoiceCPP*> voices;
    std::vector<APAudioSoundDescription*> sounds;
    
private:

    UInt activeVoices;
    UInt channel;
};

#endif /* defined(__APAudioEngine__APAudioVoiceManagerCPP__) */

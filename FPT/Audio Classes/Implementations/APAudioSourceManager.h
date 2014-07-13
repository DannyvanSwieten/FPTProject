//
//  APAudioSourceManager.h
//  FPT
//
//  Created by Danny van Swieten on 13-07-14.
//
//

#ifndef __FPT__APAudioSourceManager__
#define __FPT__APAudioSourceManager__

#include "APAudioSampleSound.h"

class APAudioSourceManager
{
public:
    APAudioSourceManager();
    ~APAudioSourceManager();
    
    void loadFile();
    
private:
    
    AudioFormatManager formatManager;
    AudioFormatReader* formatReader = nullptr;
    std::vector<APAudioSoundDescription> sounds;
};

#endif /* defined(__FPT__APAudioSourceManager__) */

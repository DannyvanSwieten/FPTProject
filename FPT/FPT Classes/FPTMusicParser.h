//
//  FPTMusicParser.h
//  FPT
//
//  Created by Danny van Swieten on 22-05-14.
//
//

#ifndef __FPT__FPTMusicParser__
#define __FPT__FPTMusicParser__

#include "../JuceLibraryCode/JuceHeader.h"
#include "FPTEventHandler.h"
#include "FPTEvent.h"

class FPTMusicParser
{
public:
    
    FPTMusicParser();
    ~FPTMusicParser();
    
    void loadMusicFile();
    void checkForEvents();
    
private:
    XmlElement* mainXmlElement;
    FPTEventHandler* eventHandler;
};

#endif /* defined(__FPT__FPTMusicParser__) */

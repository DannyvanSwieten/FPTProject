//
//  FPTEventHandler.h
//  CharacterAnalyser
//
//  Created by Danny van Swieten on 08-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __CharacterAnalyser__FPTEventHandler__
#define __CharacterAnalyser__FPTEventHandler__

#include "FPTEvent.h"
#include <vector>

class FPTEventHandler
{
public:
    FPTEventHandler();
    void addHumanEvent(FPTEvent* event);
    void addComputerEvent(FPTEvent* event);
    
private:
    
    std::vector<FPTEvent*> humanEvents;
    std::vector<FPTEvent*> computerEvents;
    
};

#endif /* defined(__CharacterAnalyser__FPTEventHandler__) */

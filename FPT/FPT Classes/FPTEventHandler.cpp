//
//  FPTEventHandler.cpp
//  CharacterAnalyser
//
//  Created by Danny van Swieten on 08-05-14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "FPTEventHandler.h"

FPTEventHandler::FPTEventHandler()
{
    
}

void FPTEventHandler::addHumanEvent(FPTEvent *event)
{
    humanEvents.push_back(event);
}

void FPTEventHandler::addComputerEvent(FPTEvent *event)
{
    computerEvents.push_back(event);
}
/*
  ==============================================================================

    FPTMidiDatabase.h
    Created: 3 Jul 2014 4:16:15pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#ifndef FPTMIDIDATABASE_H_INCLUDED
#define FPTMIDIDATABASE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "FPTMidiData.h"
#include "FPTMidiLoader.h"

class FPTMidiDatabase
{
public:
    FPTMidiDatabase();
    ~FPTMidiDatabase();
    void load();
    void loadComposition();
    
    FPTMidiData getData(){return composition;};
    
private:
    
    FPTMidiData composition;
    FPTMidiLoader* loader;
    std::vector<FPTMidiData> database;
};



#endif  // FPTMIDIDATABASE_H_INCLUDED

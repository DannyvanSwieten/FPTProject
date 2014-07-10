/*
  ==============================================================================

    FPTMidiLoader.h
    Created: 26 Jun 2014 5:27:41pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#ifndef FPTMIDILOADER_H_INCLUDED
#define FPTMIDILOADER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "FPTMidiData.h"

class FPTMidiLoader
{
public:
    FPTMidiLoader();
    FPTMidiLoader(unsigned int measureSize, unsigned int phraseSize);
    
    void setMeasureSize(unsigned int measureSize);
    void setPhraseSize(unsigned int phraseSize);
    
    FPTMidiData loadData(File dataFile);
    
private:
    
    using notes = std::vector<int>;
    
    void calculateIntervals();
    
    StringArray                     midiData;
    std::vector<StringArray>        phrases;
    std::vector<StringArray>        measures;
    
    std::vector<int>                intervals;
    std::vector<notes>              phraseIntervals;
    std::vector<notes>              measureIntervals;
    
    unsigned int measureSize;
    unsigned int phraseSize;
};



#endif  // FPTMIDILOADER_H_INCLUDED

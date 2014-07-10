/*
  ==============================================================================

    FPTMidiData.h
    Created: 3 Jul 2014 3:54:02pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#ifndef FPTMIDIDATA_H_INCLUDED
#define FPTMIDIDATA_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class FPTMidiData
{
public:
    
    using notes = std::vector<int>;
    
    String ID;
    
    std::vector<int>                intervals;
    std::vector<notes>              phraseIntervals;
    std::vector<notes>              measureIntervals;
    
private:
    

};


#endif  // FPTMIDIDATA_H_INCLUDED

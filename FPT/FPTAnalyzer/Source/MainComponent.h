/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnalysisWindowComponent.h"
#include "WaveFormComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
    bool _dataWasCalculated = 0;

private:
    
    ScopedPointer<WaveFormComponent> _drawWindow1;
    ScopedPointer<AnalysisWindowComponent> _drawWindow2;
    APAudioFileManager* _fileManager;
    ScopedPointer<Viewport> _viewPort;
    
    double* _input = nullptr;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

#endif  // MAINCOMPONENT_H_INCLUDED

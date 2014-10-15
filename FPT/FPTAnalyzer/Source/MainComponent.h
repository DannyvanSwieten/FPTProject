/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "APAudioWindowManager.h"
#include "WaveFormComponent.h"
#include "APAudioAnalysisMenu.h"

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
    
    std::unique_ptr<WaveFormComponent> _waveFormWindow;
    std::unique_ptr<APAudioWindowManager> _windowManager;
    std::unique_ptr<APAudioFileManager> _fileManager;
    std::unique_ptr<APAudioAnalysisMenu> _analysisMenu;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

#endif  // MAINCOMPONENT_H_INCLUDED

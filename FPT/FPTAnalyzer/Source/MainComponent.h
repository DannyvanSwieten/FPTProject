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
#include "FPTAnalyzerAudioProcessor.h"

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
    std::unique_ptr<Viewport> _analysisViewPort;
    std::unique_ptr<APAudioWindowManager> _windowManager;
    std::unique_ptr<APAudioFileManager> _fileManager;
    std::unique_ptr<APAudioAnalysisMenu> _analysisMenu;
    std::unique_ptr<Viewport> _waveFormViewPort;
    
    std::unique_ptr<AudioDeviceManager> _deviceManager;
    std::unique_ptr<AudioProcessorPlayer> _processorPlayer;
    std::unique_ptr<FPTAnalyzerAudioProcessor> _audioProcessor;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

#endif  // MAINCOMPONENT_H_INCLUDED

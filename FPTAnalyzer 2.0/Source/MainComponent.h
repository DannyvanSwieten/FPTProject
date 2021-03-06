/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnalysisComponent.h"
#include "AnalysisFactory.h"
#include "AudioFileManager.h"
#include "APAudioAnalysisMenu.h"
#include <memory>


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
    
    APAudio::Analysis::AnalysisFactory& getAnalysisFactory();
    APAudio::Audio::AudioFileManager& getFileManager();
    APAudioAnalysisMenu& getMenu(){return *_analysisMenu;};
    
private:
    //==============================================================================
    std::unique_ptr<AnalysisComponent> _analysisComponentTop;
    std::unique_ptr<AnalysisComponent> _analysisComponentBottom;
    
    std::unique_ptr<APAudioAnalysisMenu> _analysisMenu;
    
    APAudio::Audio::AudioFileManager _fileManager;
    APAudio::Analysis::AnalysisFactory _factory;
    
    std::vector<std::vector<float>> _pitch;
    std::vector<std::vector<float>> _amplitudes;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED

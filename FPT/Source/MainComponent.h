/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioProcessor.h"
#include "AudioProcessorEditor.h"


//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */

//extern ApplicationProperties* appProperties;

class MainContentComponent   : public Component
{
public:
    
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();
    
    void paint (Graphics&);
    void resized();
    
private:
    
    AudioDeviceManager deviceManager;
    AudioProcessorPlayer player;
    FPTAudioProcessor* audioProcessor;
    FPTAudioProcessorEditor* editor;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED

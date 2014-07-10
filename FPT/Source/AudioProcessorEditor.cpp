/*
  ==============================================================================

    FPTAudioProcessorEditor.cpp
    Created: 5 Jun 2014 4:03:32pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#include "AudioProcessorEditor.h"

FPTAudioProcessorEditor::FPTAudioProcessorEditor(AudioDeviceManager* manager,
                                           AudioProcessor& processor):
AudioProcessorEditor(&processor)
{
    setSize(getParentWidth(), getParentHeight());
    numberBox = new TextEditor();
    numberBox->setBounds(25, 25, 150, 25);
    addAndMakeVisible(numberBox);
    
    deviceManager = manager;
}

FPTAudioProcessorEditor::~FPTAudioProcessorEditor()
{
    
}

void FPTAudioProcessorEditor::resized()
{
    
}

void FPTAudioProcessorEditor::paint(juce::Graphics &context)
{
    context.fillAll (Colours::grey.withAlpha((float).7));
}


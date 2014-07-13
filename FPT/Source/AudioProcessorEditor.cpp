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
    
    numberBox->addListener(this);
    
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

void FPTAudioProcessorEditor::textEditorReturnKeyPressed (TextEditor& editor)
{
    Value number = editor.getTextValue();
    String result = number.toString();
    std::cout<<atoi(&result.toRawUTF8()[0])<<std::endl;
}


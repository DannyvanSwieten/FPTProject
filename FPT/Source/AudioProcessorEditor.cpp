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
    numberBox->setBounds(25, 25, 25, 25);
    addAndMakeVisible(numberBox);
    numberBox->addListener(this);
    
    numberBox2 = new TextEditor();
    numberBox2->setBounds(25 + 1 * 30, 25, 25, 25);
    addAndMakeVisible(numberBox2);
    numberBox2->addListener(this);
    
    numberBox3 = new TextEditor();
    numberBox3->setBounds(25 + 2 * 30, 25, 25, 25);
    addAndMakeVisible(numberBox3);
    numberBox3->addListener(this);
    
    numberBox4 = new TextEditor();
    numberBox4->setBounds(25 + 3 * 30, 25, 25, 25);
    addAndMakeVisible(numberBox4);
    numberBox4->addListener(this);
    
    loadButton = new TextButton("Load File");
    loadButton->setBounds(25, 50, 150, 25);
    addAndMakeVisible(loadButton);
    
    loadButton->addListener(this);
    
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

void FPTAudioProcessorEditor::buttonClicked(juce::Button *buttonThatWasClicked)
{
    if (buttonThatWasClicked == loadButton)
    {
        auto processor = getProcessor();
        processor->sampler->addSound(processor->fileManager.loadFile());
        processor->scheduler.addEvent(1000, [=](){processor->sampler->noteOn(60, 60);}, false);
        processor->scheduler.addEvent(1000, [=](){processor->sampler->noteOn(63, 63);}, false);
        processor->scheduler.addEvent(1000, [=](){processor->sampler->noteOn(67, 67);}, false);
        processor->scheduler.addEvent(1000, [=](){processor->sampler->noteOn(70, 71);}, false);
    }
}

void FPTAudioProcessorEditor::textEditorReturnKeyPressed (TextEditor& editor)
{
    Value number = editor.getTextValue();
    String result = number.toString();
    
    std::cout<<atoi(result.toUTF8())<<std::endl;
}


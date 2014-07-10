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
    deviceManager = manager;
    setSize(getParentWidth(), getParentHeight());
    
    setOpaque (true);
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
    context.setOpacity(.5);
}

void FPTAudioProcessorEditor::mouseDown(const juce::MouseEvent &event)
{
    repaint();
    
    if(event.getNumberOfClicks() == 2)
    {
        File file(File::getSpecialLocation (File::currentApplicationFile));
        String string = file.getFullPathName();
        string += "/Effect Chains";
        
        FileChooser myChooser ("Please select the chain you want to load...",
                               File(string),
                               "*.xml");
        
        if (myChooser.browseForFileToOpen())
        {
            XmlDocument chain(File(myChooser.getResult()));
            mainXmlElement = XmlDocument::parse(File(myChooser.getResult()));
        }
    }
}

void FPTAudioProcessorEditor::mouseUp(const juce::MouseEvent &event)
{

}

void FPTAudioProcessorEditor::mouseDrag(const juce::MouseEvent &event)
{

}

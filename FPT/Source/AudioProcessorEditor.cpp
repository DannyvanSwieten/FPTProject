/*
  ==============================================================================

    SamplerAudioProcessorEditor.cpp
    Created: 5 Jun 2014 4:03:32pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#include "SamplerAudioProcessorEditor.h"

SamplerAudioProcessorEditor::SamplerAudioProcessorEditor(AudioDeviceManager* manager,
                                           AudioProcessor& processor):
AudioProcessorEditor(&processor)
{
    deviceManager = manager;
    setSize(getParentWidth(), getParentHeight());
    
    setOpaque (true);
}

SamplerAudioProcessorEditor::~SamplerAudioProcessorEditor()
{
    
}

void SamplerAudioProcessorEditor::resized()
{
    
}

void SamplerAudioProcessorEditor::paint(juce::Graphics &context)
{
    context.fillAll (Colours::grey.withAlpha((float).7));
    context.setOpacity(.5);
}

void SamplerAudioProcessorEditor::mouseDown(const juce::MouseEvent &event)
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

void SamplerAudioProcessorEditor::mouseUp(const juce::MouseEvent &event)
{

}

void SamplerAudioProcessorEditor::mouseDrag(const juce::MouseEvent &event)
{

}

/*
  ==============================================================================

    SamplerAudioProcessorEditor.h
    Created: 5 Jun 2014 4:03:32pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#ifndef SAMPLERAUDIOPROCESSOREDITOR_H_INCLUDED
#define SAMPLERAUDIOPROCESSOREDITOR_H_INCLUDED

#include "SamplerAudioProcessor.h"

class SamplerAudioProcessorEditor : public AudioProcessorEditor
{
public:
    // Create the main controller. If no audio device manager is passed that means the editor
    // runs inside a host (as a plugin) and the device can't be changed through the editor.
    SamplerAudioProcessorEditor(AudioDeviceManager* manager, AudioProcessor& processor);
    ~SamplerAudioProcessorEditor();
    
    // Inherited from Component
    void resized() override final;
    void paint(Graphics& context) override final;
    void mouseDown(const MouseEvent& event) override;
    void mouseUp(const MouseEvent& event) override;
    void mouseDrag(const MouseEvent& event);
    
private:
    
    inline SamplerAudioProcessor* getProcessor() { return dynamic_cast<SamplerAudioProcessor*>(getAudioProcessor());}
    AudioDeviceManager* deviceManager = nullptr;
    
    AudioFormatManager formatManager;
    
    XmlElement* mainXmlElement;
};



#endif  // SAMPLERAUDIOPROCESSOREDITOR_H_INCLUDED

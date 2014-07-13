/*
  ==============================================================================

    SamplerAudioProcessorEditor.h
    Created: 5 Jun 2014 4:03:32pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#ifndef SAMPLERAUDIOPROCESSOREDITOR_H_INCLUDED
#define SAMPLERAUDIOPROCESSOREDITOR_H_INCLUDED

#include "AudioProcessor.h"
#include <vector>

class FPTAudioProcessorEditor : public AudioProcessorEditor, public TextEditor::Listener
{
public:
    // Create the main controller. If no audio device manager is passed that means the editor
    // runs inside a host (as a plugin) and the device can't be changed through the editor.
    FPTAudioProcessorEditor(AudioDeviceManager* manager, AudioProcessor& processor);
    ~FPTAudioProcessorEditor();
    
    // Inherited from Component
    
    void resized() override final;
    void paint(Graphics& context) override final;
    
    // Inherited from TextEditor::Listener
    void textEditorReturnKeyPressed (TextEditor&) override;
    
private:
    
    inline FPTAudioProcessor* getProcessor() { return dynamic_cast<FPTAudioProcessor*>(getAudioProcessor());}
    AudioDeviceManager* deviceManager = nullptr;
    ScopedPointer<TextEditor> numberBox;
    std::vector<unsigned int> numbers;
};



#endif  // SAMPLERAUDIOPROCESSOREDITOR_H_INCLUDED

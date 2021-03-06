/*
  ==============================================================================

    SamplerAudioProcessor.h
    Created: 5 Jun 2014 4:03:06pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#ifndef SAMPLERAUDIOPROCESSOR_H_INCLUDED
#define SAMPLERAUDIOPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "APAudioModule.h"
#include "APAudioVoiceManager.h"
#include "FPTScheduler.h"
#include "APAudioSourceManager.h"

class FPTAudioProcessor : public AudioProcessor
{
public:
    //==============================================================================
    FPTAudioProcessor();
    ~FPTAudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();
    
    void processBlock (juce::AudioSampleBuffer& buffer, juce::MidiBuffer& midiMessages);
    
    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;
    
    //==============================================================================
    const juce::String getName() const;
    
    int getNumParameters();
    
    float getParameter (int index);
    void setParameter (int index, float newValue);
    
    const juce::String getParameterName (int index);
    const juce::String getParameterText (int index);
    
    const juce::String getInputChannelName (int channelIndex) const;
    const juce::String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;
    
    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;
    
    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const juce::String getProgramName (int index);
    void changeProgramName (int index, const juce::String& newName);
    
    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    
    TimerValue timeStamp;
    FPTScheduler scheduler;
    APAudioVoiceManager* sampler;
    APAudioSourceManager fileManager;
    APAudioMainFrame* mainFrame;
private:
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FPTAudioProcessor)
    
};

#endif  // SAMPLERAUDIOPROCESSOR_H_INCLUDED

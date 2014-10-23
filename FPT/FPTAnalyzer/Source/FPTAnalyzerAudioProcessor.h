/*
  ==============================================================================

    FPTAnalyzerAudioProcessor.h
    Created: 23 Oct 2014 5:36:03pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#ifndef FPTANALYZERAUDIOPROCESSOR_H_INCLUDED
#define FPTANALYZERAUDIOPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "APAudioFilePlayer.h"
#include "APAudioFileManager2.h"


class FPTAnalyzerAudioProcessor: public AudioProcessor
{
public:
    FPTAnalyzerAudioProcessor();
    ~FPTAnalyzerAudioProcessor();
    
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
    
    std::unique_ptr<APAudioFilePlayer> _filePlayer;
    bool play = 0;
private:
    
    APAudioFileManager* _fileManager;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FPTAnalyzerAudioProcessor)
};



#endif  // FPTANALYZERAUDIOPROCESSOR_H_INCLUDED

/*
  ==============================================================================

    FPTAudioProcessor.cpp
    Created: 5 Jun 2014 4:03:06pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#include "AudioProcessor.h"

FPTAudioProcessor::FPTAudioProcessor()
{
    timeStamp = 0;
}

FPTAudioProcessor::~FPTAudioProcessor()
{
    
}

const String FPTAudioProcessor::getName() const
{
    return String::empty;
}

int FPTAudioProcessor::getNumParameters()
{
    return 0;
}

float FPTAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void FPTAudioProcessor::setParameter (int index, float newValue)
{
    
}

const String FPTAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String FPTAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String FPTAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String FPTAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool FPTAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool FPTAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool FPTAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool FPTAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool FPTAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double FPTAudioProcessor::getTailLengthSeconds() const
{
    return 0;
}

int FPTAudioProcessor::getNumPrograms()
{
    return 0;
}

int FPTAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FPTAudioProcessor::setCurrentProgram (int index)
{
}

const String FPTAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void FPTAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void FPTAudioProcessor::prepareToPlay (double ate, int samplesPerBlock)
{
    timeStamp = 0;
}

void FPTAudioProcessor::releaseResources()
{
    
}

void FPTAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    float* leftBuffer   = buffer.getWritePointer(0);
    float* rightBuffer  = buffer.getWritePointer(1);

    for (int i = 0; i < buffer.getNumSamples(); i++)
    {
        leftBuffer[i]   = 0;
        rightBuffer[i]  = 0;
        
        scheduler.update(timeStamp);
        timeStamp++;
    }
}

//==============================================================================
bool FPTAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an MTGSC)
}

AudioProcessorEditor* FPTAudioProcessor::createEditor()
{
    //    // This function will only be called if the processor was instantiated as
    //    // as plugin inside a sequencer. In this case, a nullptr can be cast as audio
    //    // device manager.
    
    //auto editor = new FPTAudioProcessorEditor(nullptr, *this);
    
    return nullptr;
}

//==============================================================================
void FPTAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FPTAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================

// This creates new instances of the plugin..
FPTAudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FPTAudioProcessor();
}
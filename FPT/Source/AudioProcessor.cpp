/*
  ==============================================================================

    SamplerAudioProcessor.cpp
    Created: 5 Jun 2014 4:03:06pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#include "SamplerAudioProcessor.h"

SamplerAudioProcessor::SamplerAudioProcessor()
{

}

SamplerAudioProcessor::~SamplerAudioProcessor()
{
    
}

const String SamplerAudioProcessor::getName() const
{
    return String::empty;
}

int SamplerAudioProcessor::getNumParameters()
{
    return 0;
}

float SamplerAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void SamplerAudioProcessor::setParameter (int index, float newValue)
{
    
}

const String SamplerAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String SamplerAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String SamplerAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String SamplerAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool SamplerAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool SamplerAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool SamplerAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool SamplerAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool SamplerAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double SamplerAudioProcessor::getTailLengthSeconds() const
{
    return 0;
}

int SamplerAudioProcessor::getNumPrograms()
{
    return 0;
}

int SamplerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SamplerAudioProcessor::setCurrentProgram (int index)
{
}

const String SamplerAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void SamplerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void SamplerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    timeStamp = 0;
}

void SamplerAudioProcessor::releaseResources()
{
    
}

void SamplerAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    float* leftBuffer   = buffer.getWritePointer(0);
    float* rightBuffer  = buffer.getWritePointer(1);
    
    for (int i = 0; i < buffer.getNumSamples(); i++)
    {
        leftBuffer[i]   = 0;
        rightBuffer[i]  = 0;
        
        timeStamp++;
    }
}

//==============================================================================
bool SamplerAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an MTGSC)
}

AudioProcessorEditor* SamplerAudioProcessor::createEditor()
{
    //    // This function will only be called if the processor was instantiated as
    //    // as plugin inside a sequencer. In this case, a nullptr can be cast as audio
    //    // device manager.
    
    //auto editor = new SamplerAudioProcessorEditor(nullptr, *this);
    
    return nullptr;
}

//==============================================================================
void SamplerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SamplerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SamplerAudioProcessor();
}
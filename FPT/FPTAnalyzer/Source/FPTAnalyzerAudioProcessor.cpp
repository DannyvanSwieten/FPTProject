/*
  ==============================================================================

    FPTAnalyzerAudioProcessor.cpp
    Created: 23 Oct 2014 5:35:26pm
    Author:  Danny van Swieten

  ==============================================================================
*/

#include "FPTAnalyzerAudioProcessor.h"

FPTAnalyzerAudioProcessor::FPTAnalyzerAudioProcessor()
{
    _filePlayer = std::make_unique<APAudioFilePlayer>();
}

FPTAnalyzerAudioProcessor::~FPTAnalyzerAudioProcessor()
{
    
}

const String FPTAnalyzerAudioProcessor::getName() const
{
    return String::empty;
}

int FPTAnalyzerAudioProcessor::getNumParameters()
{
    return 0;
}

float FPTAnalyzerAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void FPTAnalyzerAudioProcessor::setParameter (int index, float newValue)
{
    
}

const String FPTAnalyzerAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String FPTAnalyzerAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String FPTAnalyzerAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String FPTAnalyzerAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool FPTAnalyzerAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool FPTAnalyzerAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool FPTAnalyzerAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool FPTAnalyzerAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool FPTAnalyzerAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double FPTAnalyzerAudioProcessor::getTailLengthSeconds() const
{
    return 0;
}

int FPTAnalyzerAudioProcessor::getNumPrograms()
{
    return 0;
}

int FPTAnalyzerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FPTAnalyzerAudioProcessor::setCurrentProgram (int index)
{
}

const String FPTAnalyzerAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void FPTAnalyzerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void FPTAnalyzerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    _filePlayer->setSampleRate(sampleRate);
}

void FPTAnalyzerAudioProcessor::releaseResources()
{
    
}

void FPTAnalyzerAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    float* leftBuffer   = buffer.getWritePointer(0);
    float* rightBuffer  = buffer.getWritePointer(1);
    
    for (int i = 0; i < buffer.getNumSamples(); i++)
    {
            leftBuffer[i] = rightBuffer[i] = _filePlayer->play();
    }
}

//==============================================================================
bool FPTAnalyzerAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an MTGSC)
}

AudioProcessorEditor* FPTAnalyzerAudioProcessor::createEditor()
{
    //    // This function will only be called if the processor was instantiated as
    //    // as plugin inside a sequencer. In this case, a nullptr can be cast as audio
    //    // device manager.
    
    //auto editor = new FPTAnalyzerAudioProcessorEditor(nullptr, *this);
    
    return nullptr;
}

//==============================================================================
void FPTAnalyzerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FPTAnalyzerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================

 //This creates new instances of the plugin..
FPTAnalyzerAudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FPTAnalyzerAudioProcessor();
}
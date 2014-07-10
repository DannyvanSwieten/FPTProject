/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    juce::AudioDeviceManager::AudioDeviceSetup setup;
    setup.sampleRate = 44100;
    setup.bufferSize = 512;
    setup.outputDeviceName = "";
    setup.inputDeviceName = "";
    setup.outputChannels = 2;
    setup.inputChannels = 0;
    
//    ScopedPointer<XmlElement> savedAudioState (appProperties->getUserSettings()
//                                               ->getXmlValue ("audioDeviceState"));
    
    
    
    String errorCode = deviceManager.initialise(0, 2, nullptr, true, String::empty, &setup);
    std::cout << errorCode;
    assert(errorCode == "");
    
    audioProcessor = new FPTAudioProcessor();
    player.setProcessor(audioProcessor);
    deviceManager.addAudioCallback(&player);
    
    StringArray midiDevices = MidiInput::getDevices();
    
    for (int i = 0; i < midiDevices.size(); i++)
    {
        deviceManager.setMidiInputEnabled(midiDevices[i], true);
        deviceManager.addMidiInputCallback(midiDevices[i], &player);
    }
    
    editor = new FPTAudioProcessorEditor(&deviceManager, *audioProcessor);
    
    setSize(800, 600);
    addAndMakeVisible(*editor);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

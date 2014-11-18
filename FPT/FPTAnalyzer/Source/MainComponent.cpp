/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (1200, 800);
    
    _deviceManager = std::make_unique<AudioDeviceManager>();
    _processorPlayer = std::make_unique<AudioProcessorPlayer>();
    _audioProcessor = std::make_unique<FPTAnalyzerAudioProcessor>();
    
    _deviceManager->initialise(0, 2, nullptr, true);
    _processorPlayer->setProcessor(_audioProcessor.get());
    _deviceManager->addAudioCallback(_processorPlayer.get());
    
    _fileManager = std::make_unique<APAudioFileManager>();
    
    _analysisViewPort = std::make_unique<Viewport>();
    _analysisViewPort->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, ((getHeight()/5)*3)-2);
    
    _waveFormViewPort = std::make_unique<Viewport>();
    _waveFormViewPort->setBounds(0, 0, ((getWidth()/ 5)*4)-2, (getHeight()/4)-2);
    
    _waveFormWindow = std::make_unique<WaveFormComponent>(_fileManager.get());
    _waveFormWindow->setBounds(0, 0, ((getWidth()/ 5)*4)-2, (getHeight()/4)-2);
    _waveFormViewPort->setViewedComponent(_waveFormWindow.get(), false);
    _waveFormViewPort->setScrollBarThickness(10);
    
    _windowManager = std::make_unique<APAudioWindowManager>(_fileManager.get());
    _windowManager->getWindow(1)->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, ((getHeight()/5)*3)-2);
    _windowManager->getWindow(2)->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, 20*88);
    _windowManager->getWindow(3)->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, ((getHeight()/5)*3)-2);
    
    _analysisMenu = std::make_unique<APAudioAnalysisMenu>(_fileManager.get(),
                                                          _windowManager.get(),
                                                          _waveFormWindow.get(),
                                                          _analysisViewPort.get(),
                                                          _audioProcessor.get());
    
    _analysisMenu->setBounds((getWidth()/5) * 4, 0, getWidth()/5, getHeight());
    
    addAndMakeVisible(_waveFormWindow.get());
    addChildComponent(_windowManager->getWindow(1));
    addChildComponent(_windowManager->getWindow(2));
    addAndMakeVisible(_analysisMenu.get());
    addAndMakeVisible(_waveFormViewPort.get());
    addAndMakeVisible(_analysisViewPort.get());
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

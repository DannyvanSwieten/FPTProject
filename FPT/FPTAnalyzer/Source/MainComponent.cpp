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
    
    _fileManager = std::make_unique<APAudioFileManager>();
    
    _waveFormWindow = std::make_unique<WaveFormComponent>(_fileManager.get());
    _windowManager = std::make_unique<APAudioWindowManager>(_fileManager.get());
    _analysisMenu = std::make_unique<APAudioAnalysisMenu>(_fileManager.get(), _windowManager.get(), _waveFormWindow.get());
    
    _waveFormWindow->setBounds(0, 0, ((getWidth()/ 5)*4)-2, (getHeight()/4)-2);
    _windowManager->showWindow(1)->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, ((getHeight()/5)*3)-2);
    _analysisMenu->setBounds((getWidth()/5) * 4, 0, getWidth()/5, getHeight());
    
    addAndMakeVisible(_waveFormWindow.get());
    addAndMakeVisible(_windowManager->showWindow(1));
    addAndMakeVisible(_analysisMenu.get());
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

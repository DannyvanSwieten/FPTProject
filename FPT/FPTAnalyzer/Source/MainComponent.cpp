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
    
    _drawWindow1 = std::make_unique<WaveFormComponent>(_fileManager.get());
    _drawWindow2 = std::make_unique<AnalysisWindowComponent>(_fileManager.get());
    
    _drawWindow1->setBounds(0, 0, ((getWidth()/ 5)*4)-2, (getHeight()/4)-2);
    _drawWindow2->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, ((getHeight()/5)*3)-2);
    
    addAndMakeVisible(_drawWindow1.get());
    addAndMakeVisible(_drawWindow2.get());
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

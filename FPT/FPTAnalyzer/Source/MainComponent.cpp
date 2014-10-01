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
    
    _fileManager = new APAudioFileManager();
    
    _drawWindow1 = new WaveFormComponent(_fileManager);
    _drawWindow2 = new AnalysisWindowComponent(_fileManager);
    
    _drawWindow1->setBounds(0, 0, ((getWidth()/ 5)*4)-2, (getHeight()/4)-2);
    _drawWindow2->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, ((getHeight()/5)*3)-2);
    
    _viewPort = new Viewport();
    _viewPort->setBounds(0, 0, ((getWidth()/ 5)*4)-2, (getHeight()/4)-2);
    _viewPort->setViewedComponent(_drawWindow1);
    
    addAndMakeVisible(_viewPort);
    addAndMakeVisible(_drawWindow2);
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

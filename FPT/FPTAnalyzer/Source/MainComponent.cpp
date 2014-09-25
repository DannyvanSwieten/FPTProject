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
    _drawWindow1 = new DrawWindow();
    _drawWindow2 = new DrawWindow();
    _drawWindow3 = new DrawWindow();
    _drawWindow4 = new DrawWindow();
    _drawWindow1->setBounds(0, 0, getWidth()/2, getHeight()/2);
    _drawWindow2->setBounds(getWidth()/2, 0, getWidth()/2, getHeight()/2);
    _drawWindow3->setBounds(0, getHeight()/2, getWidth()/2, getHeight()/2);
    _drawWindow4->setBounds(getWidth()/2, getHeight()/2, getWidth()/2, getHeight()/2);
    addAndMakeVisible(_drawWindow1);
    addAndMakeVisible(_drawWindow2);
    addAndMakeVisible(_drawWindow3);
    addAndMakeVisible(_drawWindow4);
    
    analyzer = new DFTAnalyzer(1024, 1, HANNING);
    
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

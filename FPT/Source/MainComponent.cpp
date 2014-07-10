/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);
    openXMLButton = new TextButton(String("Open XML-File"));
    openXMLButton->setBounds(0, 0, 100, 20);
    openXMLButton->addListener(this);
    addAndMakeVisible(openXMLButton);
    
    musicParser = new FPTMusicParser();
}

MainContentComponent::~MainContentComponent()
{
    delete openXMLButton;
    delete musicParser;
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainContentComponent::buttonClicked(juce::Button *buttonThatWasClicked)
{
    musicParser->loadMusicFile();
    musicParser->checkForEvents();
}
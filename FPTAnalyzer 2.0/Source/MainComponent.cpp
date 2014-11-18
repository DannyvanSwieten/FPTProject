/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    _analysisComponentTop = std::make_unique<AnalysisComponent>(*this);
    
    _analysisComponentBottom = std::make_unique<AnalysisComponent>(*this);
    
    _analysisMenu = std::make_unique<APAudioAnalysisMenu>(*this);
    
    setSize(getParentWidth(), getParentHeight());
    
    _analysisComponentTop->setBounds(0, 0, (getWidth()/6) * 5, getHeight()/2);
    _analysisComponentBottom->setBounds(0, getHeight()/2, (getWidth()/6) * 5, getHeight()/2);
    
    _analysisMenu->setBounds((getWidth()/6) * 5, 0, getWidth()/6, getHeight());
    
    addAndMakeVisible(_analysisComponentTop.get());
    addAndMakeVisible(_analysisComponentBottom.get());
    addAndMakeVisible(_analysisMenu.get());
}

MainContentComponent::~MainContentComponent()
{
    
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (Colours::grey));
}

void MainContentComponent::resized()
{
    setSize(getParentWidth(), getParentHeight());
    _analysisComponentTop->setBounds(0, 0, (getWidth()/6) * 5, getHeight()/2);
    _analysisComponentBottom->setBounds(0, getHeight()/2, (getWidth()/6) * 5, getHeight()/2);
}

AnalysisFactory& MainContentComponent::getAnalysisFactory()
{
    return _factory;
}

APAudioFileManager& MainContentComponent::getFileManager()
{
    return _fileManager;
}

//std::vector<std::vector<float>>& MainContentComponent::getPitch()
//{
//    return _pitch;
//}
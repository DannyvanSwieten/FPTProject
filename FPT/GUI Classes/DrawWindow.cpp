//
//  FFTDrawWindow.cpp
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 9/25/14.
//
//

#include "MainComponent.h"

DrawWindow::DrawWindow()
{

}

DrawWindow::~DrawWindow()
{
    
}

void DrawWindow::resized()
{
    
}

void DrawWindow::mouseUp(const juce::MouseEvent &event)
{
    getDrawData();
    repaint();
}

void DrawWindow::getDrawData()
{
    MainContentComponent* mainComponent = (MainContentComponent*)getParentComponent();
    double input[1024*8];
    float phinc = 2*M_PI/1024 * 1000;
    float phase = 0;
    for(auto i = 0; i < 1024 * 8; i++)
    {
//        input[i] = (rand() % 3) - 1;//sin(phase);
        input[i] = sin(phase);//+  sin(phase * 1000);
        phase += phinc;
    }
    if(!mainComponent->_dataWasCalculated)
    {
        mainComponent->getDFTAnalyzer()->readAndAnalyse(input, 1024*8);
        mainComponent->getDFTAnalyzer()->calculateAmplitudes();
        mainComponent->getDFTAnalyzer()->calculatePhases();
        mainComponent->_dataWasCalculated = true;
    }
    _dataWasRead = true;
}

void DrawWindow::drawSpectogram(juce::Graphics& g)
{
    Path drawPath;
    MainContentComponent* mainComponent = (MainContentComponent*)getParentComponent();
    
    g.setColour(juce::Colour(juce::Colours::black));
    
    int N = mainComponent->getDFTAnalyzer()->getWindowSize()/2.0;
    int analysisSize = mainComponent->getDFTAnalyzer()->getAmplitudes().size();
    float widthScale = (float)getWidth() / analysisSize;
    float freqPerBin = 44100.0/N;
    float heightScale = (float)getHeight() / N;
//    g.setOrigin(0, getHeight());
    
    for (auto i = 0; i < analysisSize; i++)
    {
        for(auto j = 0; j < N; j++)
        {
            float alpha = (float)mainComponent->getDFTAnalyzer()->getAmplitudes()[i][j];
            g.setColour(juce::Colour(juce::Colours::black.withAlpha(alpha)));
            
            g.fillRect(i * widthScale ,
                       (float)heightScale * j,
                       (float)widthScale,
                       (float)freqPerBin*heightScale);
        }
    }
}

void DrawWindow::paint(juce::Graphics& g)
{
    
    g.fillAll(juce::Colour(juce::Colours::white));
    if(_dataWasRead)
    {
        drawSpectogram(g);
    }
}
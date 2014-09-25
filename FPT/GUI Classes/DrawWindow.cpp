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
    double input[1024*4];
    float phinc = 2*M_PI/1024;
    float phase = 0;
    for(auto i = 0; i < 1024 * 4; i++)
    {
        input[i] = (rand() % 3) - 1;//sin(phase);
        phase += phinc;
        if(i % 1024 == 0)
            phinc*=2;
    }
    mainComponent->getDFTAnalyzer()->readAndAnalyse(input, 1024*4);
    mainComponent->getDFTAnalyzer()->calculateAmplitudes();
    mainComponent->getDFTAnalyzer()->calculatePhases();
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
    float heightScale = getHeight() / 44100.0;
    
    for (auto i = 0; i < 4; i++)
    {
        for(auto j = 0; j < N; j++)
        {
            g.setColour(juce::Colour(juce::Colours::black.withAlpha((float)mainComponent->getDFTAnalyzer()->getAmplitudes()[i][j]/128)));
//            g.setColour(juce::Colour(juce::Colours::black.withAlpha(1.0f / (float)N * j)));
            
            g.fillRect(i * widthScale ,
                       (float)heightScale * j * freqPerBin,
                       (float)widthScale,
                       (float)freqPerBin*heightScale * 10);
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
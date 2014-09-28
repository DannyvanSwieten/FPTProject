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

void DrawWindow::mouseDown(const juce::MouseEvent &event)
{
    ModifierKeys modifiers = ModifierKeys::getCurrentModifiersRealtime();
    
    if(modifiers.isRightButtonDown())
    {
        PopupMenu menu;
        PopupMenu DFT;
        PopupMenu wavelet;
        
        DFT.addItem(1, "Spectogram");
        DFT.addItem(2, "Spectral Flux");
        DFT.addItem(3, "Phase Difference");
        
        wavelet.addItem(4, "Spectogram");
        wavelet.addItem(5, "Spectral Flux");
        wavelet.addItem(6, "Phase Difference");
        
        menu.addSubMenu("DFT", DFT);
        menu.addSubMenu("Wavelet", wavelet);
        
        _whatToDraw = menu.show();
    }
    
    repaint();
}

void DrawWindow::mouseUp(const juce::MouseEvent &event)
{
    
}

void DrawWindow::draw(Graphics& g)
{
    switch (_whatToDraw)
    {
        case 1:
            drawDFTSpectogram(g);
            break;
        case 2:
            getDrawData();
            drawSpectralFlux(g);
            break;
        case 3:
            break;
        default:
            
            break;
    }
}

void DrawWindow::getDrawData()
{
    _drawPath.clear();
    MainContentComponent* mainComponent = (MainContentComponent*)getParentComponent();
    DFTAnalyzer analyzer(1024, 1, HANNING);
    analyzer.readAndAnalyse(mainComponent->getData(), 1024 * 8);
    analyzer.calculateAmplitudes();
    analyzer.calculateSpectralFlux();
    int analysisSize = analyzer.getSpectralFlux().size();
    float widthScale = (float)getWidth() / analysisSize;
    double heightScale = (float)getHeight() / 144;
    
    for(auto i = 0; i < analysisSize/2; i++)
    {
        float sample = analyzer.getSpectralFlux()[i];
        _drawPath.lineTo(i * widthScale, fabs(sample * heightScale));
    }
    repaint();
}

void DrawWindow::drawTransientData(juce::Graphics& g)
{

}

void DrawWindow::drawDFTSpectogram(juce::Graphics& g)
{
    MainContentComponent* mainComponent = (MainContentComponent*)getParentComponent();
    DFTAnalyzer analyzer(1024, 1, HANNING);
    
    analyzer.readAndAnalyse(mainComponent->getData(), 1024 * 8);
    analyzer.calculateAmplitudes();
    
    g.setColour(juce::Colour(juce::Colours::black));
    
    int N = analyzer.getWindowSize()/2.0;
    int analysisSize = analyzer.getAmplitudes().size();
    float widthScale = (float)getWidth() / analysisSize;
    double heightScale = (float)getHeight() / N;
    g.setOrigin(0, getHeight());
    
    for (auto i = 0; i < analysisSize; i++)
    {
        for(auto j = 0; j < N; j++)
        {
            float alpha = (float)analyzer.getAmplitudes()[i][j];
            g.setColour(juce::Colour(juce::Colours::black.withAlpha(alpha)));
            
            g.fillRect(widthScale * i ,
                       -heightScale * j,
                       widthScale,
                       heightScale);
        }
    }
}

void DrawWindow::drawSpectralFlux(juce::Graphics &g)
{
    g.strokePath(_drawPath, juce::PathStrokeType(1.0));
}

void DrawWindow::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(juce::Colours::white));

    draw(g);
}
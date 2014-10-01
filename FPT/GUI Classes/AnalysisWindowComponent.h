//
//  AnalysisWindowComponent.h
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 9/30/14.
//
//

#ifndef FPTAnalyzer_AnalysisWindowComponent_h
#define FPTAnalyzer_AnalysisWindowComponent_h

#include "DFTAnalyzer.h"
#include "WaveletTransform.h"
#include "TransientProcessor.h"
#include "APAudioFileManager2.h"

class AnalysisWindowComponent: public Component
{
public:
    
    AnalysisWindowComponent(APAudioFileManager* fileManager);
    ~AnalysisWindowComponent();
    
    void resized()override;
    void paint(Graphics& g)override;
    void getDrawData();
    void mouseUp (const MouseEvent& event)override;
    void mouseDown(const MouseEvent& event)override;
    
private:
    
    APAudioFileManager* _fileManager;
    
    int _whatToDraw = 0;
    void draw(juce::Graphics& g);
    void drawDFTSpectogram(juce::Graphics& g);
    void drawTransientData(juce::Graphics& g);
    void drawSpectralFlux(juce::Graphics& g);
    
    void drawWaveletSpectogram(juce::Graphics& g);
    bool _dataWasRead = 0;
    Path _drawPath;
};

#endif

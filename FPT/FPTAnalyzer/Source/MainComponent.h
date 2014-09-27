/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "DFTAnalyzer.h"
#include "TransientProcessor.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class DrawWindow;

class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
    double* getData(){return _input;};
    DFTAnalyzer* getDFTAnalyzer(){return _analyzer;};
    TransientProcessor* getTransientProcessor(){return _transProcessor;};
    bool _dataWasCalculated = 0;

private:
    
    ScopedPointer<DrawWindow> _drawWindow1;
    ScopedPointer<DrawWindow> _drawWindow2;
    ScopedPointer<DrawWindow> _drawWindow3;
    ScopedPointer<DrawWindow> _drawWindow4;
    
    ScopedPointer<DFTAnalyzer> _analyzer;
    ScopedPointer<TransientProcessor> _transProcessor;
    double* _input = nullptr;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

class DrawWindow: public Component
{
public:
    
    DrawWindow();
    ~DrawWindow();
    
    void resized()override;
    void paint(Graphics& g)override;
    void getDrawData();
    void mouseUp (const MouseEvent& event)override;
    void mouseDown(const MouseEvent& event)override;
private:
    int _whatToDraw = 0;
    void draw(juce::Graphics& g);
    void drawDFTSpectogram(juce::Graphics& g);
    void drawTransientData(juce::Graphics& g);
    void drawSpectralFlux(juce::Graphics& g);
    bool _dataWasRead = 0;
    Path _drawPath;
};

#endif  // MAINCOMPONENT_H_INCLUDED

/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "DFTAnalyzer.h"


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
    DFTAnalyzer* getDFTAnalyzer(){return analyzer;};
    bool _dataWasCalculated = 0;

private:
    
    ScopedPointer<DrawWindow> _drawWindow1;
    ScopedPointer<DrawWindow> _drawWindow2;
    ScopedPointer<DrawWindow> _drawWindow3;
    ScopedPointer<DrawWindow> _drawWindow4;
    
    DFTAnalyzer* analyzer;
    
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
    
private:
    void drawSpectogram(juce::Graphics& g);
    bool _dataWasRead = 0;
};

#endif  // MAINCOMPONENT_H_INCLUDED

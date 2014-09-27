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
    
    _drawWindow1->setBounds(0, 0, (getWidth()/2)-2, (getHeight()/2)-2);
    _drawWindow2->setBounds(getWidth()/2, 0, (getWidth()/2)-2, (getHeight()/2)-2);
    _drawWindow3->setBounds(0, getHeight()/2, (getWidth()/2)-2, (getHeight()/2)-2);
    _drawWindow4->setBounds(getWidth()/2, getHeight()/2, (getWidth()/2)-2, (getHeight()/2)-2);
    
    addAndMakeVisible(_drawWindow1);
    addAndMakeVisible(_drawWindow2);
    addAndMakeVisible(_drawWindow3);
    addAndMakeVisible(_drawWindow4);
    
    _analyzer = new DFTAnalyzer(1024, 1, HANNING);
    _transProcessor= new TransientProcessor();
    
    _input = new double[1024*8];
    double phinc = (2*M_PI)/1024;
    double phase = 0;
    for(auto i = 0; i < 1024 * 8; i++)
    {
//        _input[i] = (rand() % 2) - 1;//sin(phase);
        _input[i] = sin(phase);//+  sin(phase * 1000);
        phase += phinc;
        
        if(i % 1024 == 0)
            phinc *= 3.5;
    }
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

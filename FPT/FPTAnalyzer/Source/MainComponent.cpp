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
    
    _drawWindow1 = new WaveFormComponent();
    _drawWindow2 = new AnalysisWindowComponent();
    
    _drawWindow1->setBounds(0, 0, ((getWidth()/ 5)*4)-2, (getHeight()/4)-2);
    _drawWindow2->setBounds(0, (getHeight()/4), ((getWidth()/ 5)*4)-2, ((getHeight()/5)*3)-2);
    
    addAndMakeVisible(_drawWindow1);
    addAndMakeVisible(_drawWindow2);
    
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

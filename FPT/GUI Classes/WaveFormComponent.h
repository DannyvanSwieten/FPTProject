//
//  WaveFormComponent.h
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 9/30/14.
//
//

#ifndef __FPTAnalyzer__WaveFormComponent__
#define __FPTAnalyzer__WaveFormComponent__

#include "../JuceLibraryCode/JuceHeader.h"

class WaveFormComponent: public Component
{
public:
    
    WaveFormComponent();
    ~WaveFormComponent();
    
    void resized()override;
    void paint(Graphics& g)override;
    void mouseUp (const MouseEvent& event)override;
    void mouseDown(const MouseEvent& event)override;
    
private:
    
    
};


#endif /* defined(__FPTAnalyzer__WaveFormComponent__) */

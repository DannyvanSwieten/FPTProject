//
//  WaveFormComponent.cpp
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 9/30/14.
//
//

#include "WaveFormComponent.h"

WaveFormComponent::WaveFormComponent()
{
    
}

WaveFormComponent::~WaveFormComponent()
{
    
}

void WaveFormComponent::paint(Graphics& g)
{
    g.fillAll(Colour(Colours::white));
}

void WaveFormComponent::resized()
{
    
}

void WaveFormComponent::mouseDown(const juce::MouseEvent &event)
{
    ModifierKeys modifiers = ModifierKeys::getCurrentModifiersRealtime();
    
    if(modifiers.isRightButtonDown())
    {
        PopupMenu menu;
        
        menu.addItem(1, "Load File");
        
        if (menu.show())
        {
            
        }
    }
}

void WaveFormComponent::mouseUp(const juce::MouseEvent &event)
{
    
}
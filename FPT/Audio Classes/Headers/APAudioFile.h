//
//  APAudioFile.h
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 10/1/14.
//
//

#ifndef __FPTAnalyzer__APAudioFile__
#define __FPTAnalyzer__APAudioFile__

#include "../JuceLibraryCode/JuceHeader.h"

class APAudioFile
{
public:
    
    void setAudio(AudioSampleBuffer buffer);
    void setNumChannels(int channels);
    void setNumSamples(long int samples);
    void setFileName(String name);
    
    String getName();
    const float* getAudioChannel(int index);
    int getNumChannels();
    long int getNumSamples();
    
private:
    
    AudioSampleBuffer _audio;
    String _fileName;
    int _numChannels = 0;
    long int _numSamples = 0;
};

#endif /* defined(__FPTAnalyzer__APAudioFile__) */

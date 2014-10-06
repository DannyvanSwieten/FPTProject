//
//  FrequencyAnalyzer.h
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 10/2/14.
//
//

#ifndef __FPTAnalyzer__FrequencyAnalyzer__
#define __FPTAnalyzer__FrequencyAnalyzer__
#include "YINAnalyzer.h"
#include "APAudioFileManager2.h"

class FrequencyAnalyzer
{
public:
    FrequencyAnalyzer(int N);
    void readAndAnalyse(const float* input, long int numberOfSamples);
    std::vector<float> getResult(){return _result;};
private:
    
    YINAnalyzer yin;
    int _N;
    std::vector<float> _result;
};

#endif /* defined(__FPTAnalyzer__FrequencyAnalyzer__) */

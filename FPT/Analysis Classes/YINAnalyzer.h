//
//  YINAnalyser.h
//  FPTAnalyzer
//
//  Created by Danny van Swieten on 10/2/14.
//
//

#ifndef __FPTAnalyzer__YINAnalyser__
#define __FPTAnalyzer__YINAnalyser__

#include <vector>
#include "Utility.h"

class YINAnalyzer
{
public:
    YINAnalyzer();
    ~YINAnalyzer();
    
    void init(int N);
    void process(float* audioData, int numSamples);
    float analyze(float* input);
private:
    
    void squaredDifference(float* input);
    void normalizedDifference();
    int absoluteThreshold();
    
    int _N = 0;
    std::vector<float> _tau;
    float _threshold = 0;
    float _probability = 0;
    float bla[1024];
};

#endif /* defined(__FPTAnalyzer__YINAnalyser__) */

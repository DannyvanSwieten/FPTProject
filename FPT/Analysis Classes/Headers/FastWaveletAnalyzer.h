//
//  FastWavelet.h
//  DFT
//
//  Created by Danny van Swieten on 9/22/14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __DFT__FastWavelet__
#define __DFT__FastWavelet__

#include "SpectralAnalyzer.h"

class FastWaveletAnalyzer: public SpectralAnalyzer
{
public:
    FastWaveletAnalyzer();
    ~FastWaveletAnalyzer();
    
private:
    
    void readAndAnalyse(double* input, long numberOfSamples) override;
    void calculatePhases() override;
    void calculateAmplitudes() override;
    void calculateInstantFrequencies() override;
    
};

#endif /* defined(__DFT__FastWavelet__) */

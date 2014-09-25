//
//  FastWavelet.cpp
//  DFT
//
//  Created by Danny van Swieten on 9/22/14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "FastWavelet.h"

FastWavelet::FastWavelet()
{
    
}

void FastWavelet::process(double* input ,unsigned int N)
{
    int numWavelets = log2(N);
    int num = numWavelets;
    
    std::vector<double> firstWavelet;
    
    for (auto sample = 0; sample < N; sample += 2)
    {
        firstWavelet.emplace_back(input[sample]);
    }
    _result.emplace_back(firstWavelet);
    
    for (auto wavelet = 0; wavelet < numWavelets; wavelet++)
    {
        std::vector<double> result;
        num--;
        result.resize(1<<num);
        for (auto sample = 0; sample < result.size(); sample += 2)
        {
            result[sample] = (_result[wavelet][sample]+_result[wavelet][sample+1])/2;
        }
        _result.emplace_back(result);
    }
}
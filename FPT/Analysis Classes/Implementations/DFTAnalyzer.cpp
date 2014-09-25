//
//  DFTAnalyzer.cpp
//  DFT
//
//  Created by Danny van Swieten on 9/18/14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#include "DFTAnalyzer.h"

DFTAnalyzer::DFTAnalyzer(unsigned int N, unsigned int overlap, WindowType t): SpectralAnalyzer(N, overlap)
{
    dft.init(N, t);
    _freqPerBin = 2*M_PI / N;
}

DFTAnalyzer::~DFTAnalyzer()
{
    
}

void DFTAnalyzer::readAndAnalyse(double *input, long numberOfSamples)
{
    unsigned long position = 0;
    double buffer[getWindowSize()];
    unsigned int windowSize = getWindowSize();
    unsigned int hopSize = getHopsise();
    
    while(numberOfSamples > 0)
    {
        for (auto i = 0; i < getWindowSize(); i++)
        {
            if(position < numberOfSamples)
                buffer[i] = input[position++];
            else
                buffer[i] = 0;
        }
        if (getOverlap() != 1)
            position -= (windowSize - hopSize);

        numberOfSamples -= hopSize;
        dft.calculateDFT(buffer);
        
        _analysisResult.emplace_back(dft.getResult());
    }
}

void DFTAnalyzer::calculateAmplitudes()
{
    for(auto i = 0; i < _analysisResult.size(); i++)
    {
        std::vector<double> amplitude;
        for(auto n = 0; n < dft.getSize();n++)
        {
            amplitude.emplace_back( std::abs(_analysisResult[i][n]));
        }
        _amplitudes.emplace_back(amplitude);
    }
}

void DFTAnalyzer::calculatePhases()
{
    for(auto i = 0; i < _analysisResult.size(); i++)
    {
        std::vector<double> phase;
        for(auto n = 0; n < dft.getSize();n++)
        {
            phase.emplace_back(std::arg(_analysisResult[i][n]));
        }
        _phases.emplace_back(phase);
    }
    
    for(auto i = 1; i < _analysisResult.size(); i++)
    {
        for(auto n = 0; n < dft.getSize();n++)
        {
            while(_phases[i][n] - _phases[i-1][n] > M_PI)
                _phases[i][n] -= 2*M_PI;
            while(_phases[i][n] - _phases[i-1][n] < -M_PI)
                _phases[i][n] += 2*M_PI;
        }
    }
}

void DFTAnalyzer::calculateInstantFrequencies()
{
    for(auto i = 1; i < _phases.size(); i++)
    {
        std::vector<double> freq;
        for(auto j = 0; j < dft.getSize(); j++)
        {
            double wrappedPhaseDetermination = phaseWrap((_phases[i][j] - _phases[i-1][j]) - (getHopsise() * (_freqPerBin) * j), M_PI);
            freq.emplace_back((_freqPerBin * j) + (wrappedPhaseDetermination/getHopsise()));
        }
        _trueFrequencies.emplace_back(freq);
    }
}
//
//  DFTAnalyzer.h
//  DFT
//
//  Created by Danny van Swieten on 9/18/14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __DFT__DFTAnalyzer__
#define __DFT__DFTAnalyzer__

#include "SpectralAnalyzer.h"
#include "DFT.h"

class DFTAnalyzer: public SpectralAnalyzer
{
public:
    
    DFTAnalyzer(unsigned int N, unsigned int overlap, WindowType t);
    ~DFTAnalyzer();
    
    void readAndAnalyse(double* input, long numberOfSamples) override;
    void calculateAmplitudes()override;
    void calculatePhases()override;
    void calculateInstantFrequencies()override;
    void calculateSpectralFlux();
    std::vector<std::vector<double>> getAmplitudes(){return _amplitudes;};
    std::vector<std::vector<double>> getPhases(){return _phases;};
    std::vector<std::vector<double>> getFrequenies(){return _trueFrequencies;};
    std::vector<double> getSpectralFlux(){return _spectralFlux;};
private:
    
    class DFT dft;
    double _freqPerBin = 0;
    std::vector<std::complex<double>> _buffer;
    std::vector<std::vector<std::complex<double>>> _analysisResult;
    std::vector<std::vector<double>> _phases;
    std::vector<std::vector<double>> _amplitudes;
    std::vector<std::vector<double>> _trueFrequencies;
    std::vector<double> _spectralFlux;
};

#endif /* defined(__DFT__DFTAnalyzer__) */

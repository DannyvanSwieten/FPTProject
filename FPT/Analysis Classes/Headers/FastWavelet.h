//
//  FastWavelet.h
//  DFT
//
//  Created by Danny van Swieten on 9/22/14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef __DFT__FastWavelet__
#define __DFT__FastWavelet__

#include <math.h>
#include <vector>

class FastWavelet
{
public:
    FastWavelet();
    
    void process(double* input ,unsigned int N, int direction);
    std::vector<std::vector<double>> _result;
private:
    void forward(double* input ,unsigned int N);
    void backward(double* input ,unsigned int N);
};

#endif /* defined(__DFT__FastWavelet__) */

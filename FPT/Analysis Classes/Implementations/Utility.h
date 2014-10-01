//
//  Utility.h
//  DFT
//
//  Created by Danny van Swieten on 9/18/14.
//  Copyright (c) 2014 Danny van Swieten. All rights reserved.
//

#ifndef DFT_Utility_h
#define DFT_Utility_h

#include <math.h>
#include <algorithm>

enum WindowType
{
    HANNING,
    HAMMING,
    BLACKMAN
};

static inline void createWindow(WindowType t, double* output, unsigned int N)
{
    switch (t) {
        case HANNING:
            for (auto i = 0; i < N; i++)
            {
                output[i] = 0.5 * (1 - cos((2*M_PI * i) / N));
            }
            break;
            
        default:
            break;
    }
}

static inline double phaseWrap(double x, double d)
{
    // Optimize this ###
    double d2 = 2*d;
    double y = fmod(x, d2);
    
    return (y>d) ? (y-d2) : ((y<-d) ? (y+d2) : (y));
}

static inline void normalize(float* input, int size)
{
    float max = 0.0;
    float norm = 0.0;
    
    for(auto i = 0; i < size; i++)
        max = std::max(max, input[i]);
    
    norm = 1.0 / max;
    for(auto i = 0; i < size; i++)
        input[i] *= norm;
}

#endif

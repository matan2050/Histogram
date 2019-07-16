#pragma once
#include <type_traits>

class Histogram
{
// public methods
public:
    Histogram(float* rawData, unsigned int rawDataLength, unsigned int numBins);
    void GetPercentileValue(float percentile);

//private methods
private:
    void _InitBuffers(unsigned int numBins);
    void _FinalizeBuffers();

// members
private:
    float* binMax = nullptr;
    float* binMin = nullptr;
    unsigned int* binCounts = nullptr;
    unsigned int nBins;
    float binLength;
};

#pragma once

class Histogram
{
// public methods
public:
    Histogram(const float* data, unsigned int dataLength, unsigned int numBins);
    void GetPercentileValue(float percentile) const;

//private methods
private:
    void _InitBuffers(unsigned int numBins);
    void _FinalizeBuffers();
    void _FindMinMax(const float* data, unsigned int dataLength, float& min, float& max);
    void _FillBins(const float* data, unsigned int dataLength);
    void _SetBinRange(int min, int max);

// members
private:
    float* binMax = nullptr;
    float* binMin = nullptr;
    unsigned int* binCounts = nullptr;
    unsigned int nBins;
    float binLength;
};

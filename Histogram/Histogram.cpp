#include "Histogram.h"

Histogram::Histogram(const float* data, unsigned int dataLength, unsigned int numBins)
{
    nBins = numBins;
    _InitBuffers(nBins);

    float min, max;
    _FindMinMax(data, dataLength, min, max);
    binLength = (max - min) / (float)nBins;

    _FillBins(data, dataLength);
}

void Histogram::_InitBuffers(unsigned int numBins)
{
    binCounts = new unsigned int[numBins] {};
    binMin = new float[numBins] {};
    binMax = new float[numBins] {};
}

void Histogram::_FinalizeBuffers()
{
    delete[] binCounts;
    delete[] binMin;
    delete[] binMin;
}

void Histogram::_FindMinMax(const float* data, unsigned int dataLength, float& min, float& max)
{
    const float* dataIndexer = data;

    min = *dataIndexer;
    max = *dataIndexer;
    for (int i = 0; i < dataLength; i++, dataIndexer++)
    { 
        if (*dataIndexer > max) { max = *dataIndexer; }
        if (*dataIndexer < min) { min = *dataIndexer; }
    }
}

void Histogram::_FillBins(const float* data, unsigned int dataLength)
{
    const float* dataIndexer = data;
    unsigned int bin;

    for (int i = 0; i < dataLength; i++, dataIndexer++)
    {
        bin = (unsigned int)(*dataIndexer / binLength);
        binCounts[bin]++;
    }
}
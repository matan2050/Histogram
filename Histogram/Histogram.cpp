#include "Histogram.h"

Histogram::Histogram(float* rawData, unsigned int rawDataLength, unsigned int numBins)
{
    nBins = numBins;
    _InitBuffers(nBins);
}

void Histogram::_InitBuffers(unsigned int numBins)
{
    binCounts = new unsigned int[numBins];
    binMin = new float[numBins];
    binMax = new float[numBins];
}

void Histogram::_FinalizeBuffers()
{
    delete[] binCounts;
    delete[] binMin;
    delete[] binMin;
}
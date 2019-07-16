#include "Histogram.h"

int main()
{
    // initialize buffer for histogram
    int rawDataLength = 1024 * 1024;
    float* rawData = new float[rawDataLength];

    for (int i = 0; i < rawDataLength; i++)
    {
        rawData[i] = (float)i;
    }

    int nBins = 100;
    Histogram hist = Histogram(rawData, rawDataLength, nBins);

    // finalize unittest
    delete[] rawData;
}
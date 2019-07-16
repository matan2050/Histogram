#include "Histogram.h"

int main()
{
    // initialize buffer for histogram
    int raw_data_length = 1024 * 1024;
    float* raw_data = new float[raw_data_length];

    for (int i = 0; i < raw_data_length; i++)
    {
        raw_data[i] = (float)i;
    }

    int num_bins = 100;
    Histogram hist = Histogram(raw_data, raw_data_length, num_bins);

    // finalize unittest
    delete[] raw_data;
}
#include <iostream>
#include <time.h>
#include "Histogram.h"

int main()
{
    // initialize buffer for histogram
    int raw_data_length = 256 * 256 * 256;
    float* raw_data = new float[raw_data_length];

    for (int i = 0; i < raw_data_length; i++)
    {
        raw_data[i] = (float)i;
    }

    clock_t begin = clock();
    int num_bins = 100;
    int benchmark_repetitions = 100;
    for (int i = 0; i < benchmark_repetitions; i++)
    {
        Histogram hist = Histogram(raw_data, raw_data_length, num_bins);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout << "generate histogram = " << time_spent / benchmark_repetitions << "\n";

    /*begin = clock();
    for (int i = 0; i < benchmark_repetitions; i++)
    {
        hist.GetPercentileValue(95);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout << "get 95th percentile = " << time_spent / benchmark_repetitions << "\n";*/
    // finalize unittest
    delete[] raw_data;
}
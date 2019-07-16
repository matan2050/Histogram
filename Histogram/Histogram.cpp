#include "Histogram.h"

Histogram::Histogram(const float* data, unsigned int data_length, unsigned int num_bins)
{
    num_bins_ = num_bins;
    InitBuffers(num_bins_);

    float min, max;
    FindMinMax(data, data_length, min, max);
    bin_length_ = (max - min) / (float)num_bins_;

    FillBins(data, data_length);
    SetBinRange(min, max);
}

float Histogram::GetPercentileValue(float percentile) const
{
    unsigned int corresponding_bin;
    unsigned int accumulated_elements = 0;
    for (int i = 0; i < num_bins_; i++)
    {
        accumulated_elements += bin_counts_[i];
        
        float current_percentile = (accumulated_elements / total_num_elements_) * 100;
        if (current_percentile >= percentile)
        {
            corresponding_bin = i;
            break;
        }
    }

    return bin_min_[corresponding_bin];
}

void Histogram::InitBuffers(unsigned int num_bins)
{
    bin_counts_ = new unsigned int[num_bins] {};
    bin_min_ = new float[num_bins] {};
    bin_max_ = new float[num_bins] {};
}

void Histogram::FinalizeBuffers()
{
    delete[] bin_counts_;
    delete[] bin_min_;
    delete[] bin_min_;
}

void Histogram::FindMinMax(const float* data, unsigned int data_length, float& min, float& max)
{
    const float* data_indexer = data;

    min = *data_indexer;
    max = *data_indexer;
    for (; data_indexer < data + data_length; data_indexer++)
    { 
        if (*data_indexer > max) { max = *data_indexer; }
        if (*data_indexer < min) { min = *data_indexer; }
    }
}

void Histogram::FillBins(const float* data, unsigned int data_length)
{
    const float* data_indexer = data;
    unsigned int bin;

    for (;data_indexer < data + data_length; data_indexer++)
    {
        bin = (unsigned int)(*data_indexer / bin_length_);
        bin_counts_[bin]++;
    }
}

void Histogram::SetBinRange(int min, int max)
{
    for (int i = 0; i < num_bins_; i++)
    {
        bin_min_[i] = min + i * bin_length_;
        bin_max_[num_bins_ - 1 - i] = max - i * bin_length_;
    }
}
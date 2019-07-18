#pragma once

class Histogram
{
public:
    Histogram(const float* data, unsigned int dataLength, unsigned int numBins);
    ~Histogram();
    float GetPercentileValue(float percentile) const;

private:
    void InitBuffers(unsigned int numBins);
    void FinalizeBuffers();
    void FindMinMax(const float* data, unsigned int dataLength, float& min, float& max) const;
    void FillBins(const float* data, unsigned int dataLength);
    void SetBinRange(int min, int max);

    float* bin_max_ = nullptr;
    float* bin_min_ = nullptr;
    unsigned int* bin_counts_ = nullptr;

    unsigned int num_bins_;
    unsigned int total_num_elements_;
    float bin_length_;
};

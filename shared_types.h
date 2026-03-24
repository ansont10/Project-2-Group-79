// shared_types.h
// I put lap record in here so both files can use it.

#pragma once

struct LapRecord
{
    int raceId;
    int driverId;
    int lap;
    int milliseconds;
    bool isOccupied = false;
    long long getCompositeKey() const
    {
        return (long long)raceId * 1000000 + (long long)driverId * 1000 + lap;
    }
};

// this holds results from one benchmark run so we can print the table at the end
// had to make this because i needed to store results from both algorithms together
struct BenchmarkResult
{
    double loadFactorUsed;
    int tableSizeForRun;
    long long linearCollisions;
    long long linearInsertTimeMs;
    double linearAvgSearchTimeUs;
    long long quadCollisions;
    long long quadInsertTimeMs;
    double quadAvgSearchTimeUs;
};
// shared_types.h

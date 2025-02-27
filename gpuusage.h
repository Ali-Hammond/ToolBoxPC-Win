#ifndef GPUUSAGE_H
#define GPUUSAGE_H

#include <string>

class GpuUsage {
public:
    static std::string detectGpuVendor();
    static float getGpuUsage();
};

#endif // GPUUSAGE_H

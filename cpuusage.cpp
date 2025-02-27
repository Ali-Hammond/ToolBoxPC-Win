#include "cpuusage.h"
#include <Windows.h>
#include <psapi.h>
#include <QDebug>

CpuUsage::CpuUsage(QObject *parent) : QObject(parent)
{
    // Constructor logic (optional)
}

CpuUsage::~CpuUsage()
{
    // Destructor logic (optional)
}

int CpuUsage::getCpuUsage()
{
    FILETIME idleTime, kernelTime, userTime;
    if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
        ULONGLONG idle = ((ULONGLONG)idleTime.dwLowDateTime | ((ULONGLONG)idleTime.dwHighDateTime << 32));
        ULONGLONG kernel = ((ULONGLONG)kernelTime.dwLowDateTime | ((ULONGLONG)kernelTime.dwHighDateTime << 32));
        ULONGLONG user = ((ULONGLONG)userTime.dwLowDateTime | ((ULONGLONG)userTime.dwHighDateTime << 32));

        ULONGLONG total = kernel + user;
        ULONGLONG idleDelta = idle - lastIdleTime;
        ULONGLONG totalDelta = total - lastTotalTime;

        lastIdleTime = idle;
        lastTotalTime = total;

        if (totalDelta == 0) return 0;  // Prevent division by zero

        return (int)((1.0 - ((double)idleDelta / (double)totalDelta)) * 100.0);
    }
    return 0;
}

#ifndef CPUUSAGE_H
#define CPUUSAGE_H
#include <windows.h>

#include <QObject>

class CpuUsage : public QObject
{
    Q_OBJECT

public:
    explicit CpuUsage(QObject *parent = nullptr);
    ~CpuUsage();
    int getCpuUsage(); // Function to get the CPU usage

private:
    ULONGLONG lastIdleTime = 0;
    ULONGLONG lastTotalTime = 0;
};

#endif // CPUUSAGE_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include "gpuusage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cpuUsage()  // Initialize CpuUsage instance
{
    ui->setupUi(this);

    // Set up a QTimer to update CPU usage periodically
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCpuUsage);
    timer->start(900);  // Update every
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCpuUsage()
{
    int usage = cpuUsage.getCpuUsage();  // Get the actual CPU usage value (0-100)
    ui->CPUprogressBar->setValue(usage);  // Update the progress bar with the CPU usage
    float gpuUsage = GpuUsage::getGpuUsage();
    ui->GPUprogressBar->setValue(static_cast<int>(gpuUsage));
}

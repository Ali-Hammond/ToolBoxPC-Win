#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cpuusage.h" // Include the CpuUsage class header

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateCpuUsage();

private:
    Ui::MainWindow *ui;
    CpuUsage cpuUsage;  // Declare CpuUsage instance
};

#endif // MAINWINDOW_H

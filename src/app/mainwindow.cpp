#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("My Qt App"));
    resize(800, 600);
}

MainWindow::~MainWindow()
{
}
#include "bmpWnd.h"
#include <iostream>

BmpWnd::BmpWnd(QWidget* parent)
    : QWidget(parent)
{
    bitmap.load("/Users/thierry/Desktop/imageProc/src/assets/test.bmp");
}

void BmpWnd::paintEvent(QPaintEvent* event)
{
    // Call the base class paintEvent function
    QWidget::paintEvent(event);

    // Create a QPainter object
    QPainter painter(this);

    // Draw the bitmap at a specific position (e.g., top-left corner)
    painter.drawPixmap(0, 0, bitmap);
}
#ifndef BMPWND
#define BMPWND

#include <QWidget>
#include <QPainter>

class BmpWnd : public QWidget {
    Q_OBJECT
public:
    BmpWnd(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QPixmap bitmap;
};
#endif /* BMPWND */